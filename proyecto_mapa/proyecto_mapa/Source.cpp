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
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Obtener la posición del mouse en la ventana
                    Vector2i mousePos = Mouse::getPosition(window);
                    cout << "Clic en posición: (" << mousePos.x << ", " << mousePos.y << ")" << endl;
                }
            }
        }
      
        window.clear();
        window.draw(mapSprite);
        window.display();
    }
    return 0;
}