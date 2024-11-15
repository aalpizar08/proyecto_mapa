#include <iostream>
#include <SFML/Graphics.hpp>
#include "point.h"
#include "route.h"
#include "string"
using namespace std;
using namespace sf;

int main() {
    Route route;
    
    RenderWindow window(VideoMode(1166, 712), "Mapa");
    Texture map;
    if (!map.loadFromFile("resources/guanacaste.png")) {
        cout << "Error al cargar mapa" << endl;
    }
    Sprite mapSprite;
    mapSprite.setTexture(map);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {//cerrar ventana
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    cout << "Clic en posicion: (" << mousePos.x << ", " << mousePos.y << ")" << endl;
                    Vector2f spotPosition(mousePos.x, mousePos.y);
                    Point point(spotPosition);
                    route.createRoute(point);
                }
            }
        }
       
        window.clear();
        window.draw(mapSprite);
        route.printRoute(window);
        route.curve(window);
        //window.draw(spot);
        window.display();
    }
    return 0;
}