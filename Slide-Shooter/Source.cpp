#include "Scene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Clock clock;
    Scene scene;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();
        scene.update(dt);

        window.clear();
        scene.draw(window, sf::RenderStates::Default);
        window.display();
    }

    return 0;
}
