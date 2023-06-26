#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(float x, float y, float maxRange);
    void Draw(sf::RenderWindow& window);
    void Move();

    sf::RectangleShape shape;
    float maxRange;
    float startX;
    float moveSpeed = 0.5f; // adjust this value to make the bullets fly slower
};

#endif
