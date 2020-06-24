#include <SFML/Graphics.hpp>
#include "UFO.hpp"
#include "Cloud.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Parkour!");

    UFO ufo(sf::Vector2f(400, 300));
    Cloud cloud(sf::Vector2f(100, 100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    ufo.setX(ufo.getX() - 5);
                }
                if (event.key.code == sf::Keyboard::D) {
                    ufo.setX(ufo.getX() + 5);
                }
                if (event.key.code == sf::Keyboard::Z) {
                    ufo.setY(ufo.getY() - 5);
                }
                if (event.key.code == sf::Keyboard::S) {
                    ufo.setY(ufo.getY() + 5);
                }
            }
        }

        window.clear();
        ufo.draw(window);
        cloud.draw(window);

        if (ufo.doesIntersect(cloud)) {
            window.close();
        }


        window.display();
    }

    return 0;
}
