#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(740, 575), "Mapa Puntarenas");
    Texture map;
    if (!map.loadFromFile("C:/Users/aleja/Desktop/programming/repositorio-Proyecto II/proyecto_mapa/resources/puntarenasMap.png")) {
        return -1;
    }
    Sprite mapSprite;
    mapSprite.setTexture(map);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(mapSprite);
        window.display();
    }
    return 0;
}