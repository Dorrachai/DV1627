#include "Meteor.h"

Meteor::Meteor(float x, float y)
{
    this->x = x;
    this->y = y;

    shape.setPosition(x, y);
    shape.setRadius(30.f);
    shape.setFillColor(sf::Color::Red);
}

void Meteor::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Meteor::Move()
{
    shape.move(-moveSpeed, 0.f);
}
