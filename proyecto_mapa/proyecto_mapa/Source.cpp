#include <iostream>
#include <SFML/Graphics.hpp>
#include "point.h"
#include "route.h"
#include "string"
#include "routesList.h"
using namespace std;
using namespace sf;
int main() {
    int option = 0;
    string nameRoute, namePoint;
    Route route;//ruta
    routesList list;//lista de rutas
    //fuente
    Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        cout << "error al cargar la fuente" << endl;
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(Color::Black);
    //mapa
    Texture map;
    if (!map.loadFromFile("resources/guanacaste.png")) {
        cout << "Error al cargar mapa" << endl;
    }
    Sprite mapSprite;
    mapSprite.setTexture(map);
    //inicio del menu en consola
    while (option != 3) {
        cout << "Bienvenido al menu principal" << endl;
        cout << "Digite una opcion mediante un numero" << endl;
        cout << "1) Crear ruta turistica" <<  endl;
        cout << "2) Cargar rutas" << endl;
        cout << "3) Salir" << endl;
        cin >> option;
        if (option == 1) {
            cout << "Digite el nombre de la ruta:" << endl;
            cin >> nameRoute;
        }
        RenderWindow window(VideoMode(1166, 712), "Mapa");//ventana
        switch (option){
        case 1://Crear ruta turistica, aqui se usa el sfml
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {//cerrar ventana
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                    if (event.type == Event::MouseButtonPressed) {
                        if (event.mouseButton.button == Mouse::Left) {
                            Vector2i mousePos = Mouse::getPosition(window);
                            Vector2f spotPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));//static_cast para convertir los valores a flotantes
                            cout << "Digite el nombre del lugar: " << endl;
                            cin >> namePoint;
                            Point point(namePoint, spotPosition);
                            route.createRoute(point);
                        }
                    }
                }
                window.clear();
                window.draw(mapSprite);
                route.printRoute(window);
                route.printName(window,text);
                route.curve(window);
                window.display();
            }
            break;
        default:
            break;
        }
    }

    
    return 0;
}