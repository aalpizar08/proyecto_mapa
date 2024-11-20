#include "route.h"
void Route::createRoute(Point point) {
	nodePoint* newPoint = new nodePoint(point);
	newPoint->point = point;
	if (head == nullptr) {
		head = newPoint;
		tail = newPoint;
	}
	else {
		tail->next = newPoint;
		newPoint->prev = tail;
		tail = newPoint;
	}
}
void Route::deletePoint(Vector2f mousePos){
    nodePoint* running = head;
    while (running != nullptr) {
        
        running = running->next;
    }
}
void Route::editRoute(RenderWindow& window, Event& event, bool& click) {
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));//convierte los pixeles ern coordenadas
    Vector2f offset;
    static nodePoint* selected = nullptr;//es el punto seleccionado por el raton
    nodePoint* running = head;
    if (event.type == Event::MouseButtonPressed && (event.mouseButton.button == Mouse::Left)) {//mover un punto arrastrandolo con el raton
        while (running != nullptr) {
            if (running->point.getPoint().getGlobalBounds().contains(mousePos)) {
                selected = running;
                offset = mousePos - running->point.getXY();
                click = true;
                break;
            }
            running = running->next;
        }
    }
    if ((event.type == Event::MouseMoved) && (click)) {//mueve el punto
        running->point.setXY(mousePos - offset);
    }
    if ((event.type == Event::MouseButtonReleased) && (event.mouseButton.button == Mouse::Left)) {//detecta cuando se suelta el click
        click = false;
        selected = nullptr;
    }
    if ((event.type == Event::MouseButtonPressed) && (event.mouseButton.button == Mouse::Right)) {
        nodePoint* running = head;
        while (running != nullptr) {
            if (running->point.getPoint().getGlobalBounds().contains(mousePos)) {//encuentra un punto para eliminar mediante clic
                if (running == head && running == tail) {
                    head = nullptr;
                    tail = nullptr;
                }
                else if (running == head) {
                    head = head->next;
                    head->prev = nullptr;
                }
                else if (running == tail) {
                    tail = tail->prev;
                    tail->prev = nullptr;
                }
                else {
                    running->prev->next = running->next;
                    running->next->prev = running->prev;
                }
                delete running;
                return;
            }
            running = running->next;
        }
    }
}
void Route::printRoute(RenderWindow& window){
	nodePoint* running = head;
	while (running != nullptr) {
        running->point.printPoint(window);
		running = running->next;
	}
    curve(window);
}
void Route::curve(RenderWindow& window) {
    if (head != nullptr) {
        nodePoint* running = head;
        //estos nodos funcionan para siempre conectar el punto actual con el anterior
        nodePoint* p0 = running;
        nodePoint* p1 = p0->next;
        while (p1 != nullptr) {
            Point mid((p0->point.getXY().x + p1->point.getXY().x) / 2,
                p0->point.getXY().y + 100);//punto medio, no se visualiza pero funciona para hacer la curva
            for (float t = 0; t <= 1; t += 0.005f) {
                //la curva se genera mediante la formula de la curva de bezier y ademas se usan circulos pequeños para hacer la curva
                float x = (1 - t) * (1 - t) * p0->point.getXY().x + 2 * (1 - t) * t * mid.getXY().x + t * t * p1->point.getXY().x;
                float y = (1 - t) * (1 - t) * p0->point.getXY().y + 2 * (1 - t) * t * mid.getXY().y + t * t * p1->point.getXY().y;
                //la formula de la curva es la de la cuadratica
                Vector2f bezierPoint(x, y);
                CircleShape curvePoint(2.0f);
                curvePoint.setFillColor(Color::Red);
                curvePoint.setPosition(bezierPoint);
                window.draw(curvePoint);
            }
            //avanza los dos nodos para adelante
            p0 = p1;
            p1 = p1->next;
        }
    }
}
void Route::printName(RenderWindow& window, Text& text){
    if (head != nullptr) {
        nodePoint* running;
        running = head;
        while (running != nullptr) {
            text.setString(running->point.getName());
            text.setPosition(running->point.getXY().x, running->point.getXY().y - 15);
            window.draw(text);
            running = running->next;
        }
    }
}
bool Route::isInNodePoint(string name){
    nodePoint* runninng = head;
    while (runninng != nullptr) {
        if (runninng->point.getName() == name) {
            return true;
        }
        runninng = runninng->next;
    }
    return false;
}
void Route::saveRoutesPoint(string& routesFile){
    nodePoint* running = head;
    ofstream route(routesFile,ios::app);
    if (route.fail()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    while (running != nullptr) {
        route << running->point.getName() <<" " << running->point.getX() <<" " << running->point.getY() << endl;
        running = running->next;
    }
    route.close();
}

            
           


                    
                   
                

