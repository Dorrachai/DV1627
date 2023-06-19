#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "By-thre21");

    Player player(sf::Vector2f(0.f, window.getSize().y / 2.f - 30.f));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            player.handleInput(event);  // Pass the event to the player

            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update();  // Update the player

        window.clear();
        player.draw(window);  // Draw the player
        window.display();
    }

    return 0;
}
