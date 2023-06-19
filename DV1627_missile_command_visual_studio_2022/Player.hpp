#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position);

    void handleInput(const sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);  // Add this line

private:
    sf::RectangleShape m_playerShape[4];
};

#endif
