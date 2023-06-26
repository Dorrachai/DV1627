#ifndef METEOR_H
#define METEOR_H

#include <SFML/Graphics.hpp>

class Meteor
{
public:
    Meteor(float x, float y);
    void Draw(sf::RenderWindow& window);
    void Move();

    float x, y;
    sf::CircleShape shape;
    float moveSpeed = 0.03f; // Reduce the speed by a factor of 0.25
};

#endif
