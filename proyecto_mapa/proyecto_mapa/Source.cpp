#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "point.h"
#include "route.h"
#include "string"
#include "routesList.h"
using namespace std;
using namespace sf;
int main() {
    int option = 0;
    string routesFile = "resources/routesFile";
    //fuente
    Font font;
    if (!font.loadFromFile("resources/arial.ttf")) {
        cout << "error al cargar la fuente" << endl;
        return -1;
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(Color::Black);
    //mapa
    Texture map;
    if (!map.loadFromFile("resources/guanacaste.png")) {
        cout << "Error al cargar mapa" << endl;
        return -1;
    }
    Sprite mapSprite;
    mapSprite.setTexture(map);
    //inicio del menu en consola
    while (option != 4) {
        bool click = false;
        string nameRoute, namePoint, nameSelected;
        Route route;//ruta
        routesList list;//lista de rutas
        system("CLS");
        cout << "Bienvenido al menu principal" << endl;
        cout << "Digite una opcion mediante un numero" << endl;
        cout << "1) Crear ruta turistica" <<  endl;
        cout << "2) Ver rutas guardadas" << endl;
        cout << "3) Editar ruta" << endl;
        cout << "4) Salir" << endl;
        cin >> option;
        RenderWindow window(VideoMode(1166, 712), "Mapa");//ventana
        switch (option){
        case 1://Crear ruta turistica
            system("CLS");
            if (option == 1) {
                cout << "Digite el nombre de la ruta:" << endl;
                cin >> nameRoute;
            }
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
                            route.createRoute(point);//se crea la ruta
                        }
                    }
                }
                window.clear();
                window.draw(mapSprite);
                route.printName(window, text);
                route.printRoute(window);//crea puntos
                route.curve(window);
                window.display();
            }
            list.saveRoute(nameRoute, route);//se guarda fuera de while para que solo se guarde una vez
            list.saveRoutes(routesFile);//se guarda en archivo txt
            break;
        case 2://imprimir una ruta ya guardada
            system("CLS");
            list.printNames();
            cout << "Digite el nombre de la ruta que desea ver: " << endl;
            cin >> nameSelected;
            cout << "Se va a imprimir la ruta " << nameSelected << endl;
            cout << "Para terminar salir cierre la ventana" << endl;
            system("PAUSE");
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        list.displayRoute(window, text, nameSelected);
                        window.close();
                    }
                } 
            }
            break;
        case 3://editar
            system("CLS");
            list.printNames();
            cout << "Digite el nombre de la ruta que desea editar: " << endl;
            cin >> nameSelected;
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                    list.displayRoute(window, text, nameSelected);
                    list.selectRouteToEdit(window, event, click, nameSelected);
                }
            }
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    }
    return 0;
}