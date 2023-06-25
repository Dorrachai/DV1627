#include "Scene.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Clock clock;
    sf::Time timeSinceLastSpawn = sf::Time::Zero;
    sf::Time spawnInterval = sf::seconds(1.0f);

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
        timeSinceLastSpawn += sf::seconds(dt);

        if (timeSinceLastSpawn >= spawnInterval)
        {
            scene.addMeteor();
            timeSinceLastSpawn = sf::Time::Zero;
        }

        scene.update(dt);

        window.clear();
        scene.draw(window, sf::RenderStates::Default);
        window.display();
    }

    return 0;
}
