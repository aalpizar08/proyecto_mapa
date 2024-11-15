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
void Route::printRoute(RenderWindow& window){
	nodePoint* aux = head;
	while (aux != nullptr) {
		CircleShape point(6.0f);
		point.setFillColor(Color::Red);
		point.setPosition(aux->point.getXY());
		window.draw(point);
		aux = aux->next;
	}
}
void Route::curve(RenderWindow& window) {
    nodePoint* aux = head;
    if (aux != nullptr) {
        //estos nodos funcionan para siempre conectar el punto actual con el anterior
        nodePoint* p0 = aux;
        nodePoint* p1 = p0->next;
        while (p1 != nullptr) {
            Point mid((p0->point.getXY().x + p1->point.getXY().x) / 2,
                p0->point.getXY().y - 100);//punto medio, no se visualiza pero funciona para hacer la curva
            for (float t = 0; t <= 1; t += 0.005f) {
                //la curva se genera mediante la formula de la curva de bezier y ademas se usan circulos pequeños para hacer la curva
                float x = (1 - t) * (1 - t) * p0->point.getXY().x + 2 * (1 - t) * t * mid.getXY().x + t * t * p1->point.getXY().x;
                float y = (1 - t) * (1 - t) * p0->point.getXY().y + 2 * (1 - t) * t * mid.getXY().y + t * t * p1->point.getXY().y;
                //la formula de la curva es la de la cuadratica
                Vector2f bezierPoint(x, y);
                CircleShape curvePoint(2.5f);
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

            
           


                    
                   
                

