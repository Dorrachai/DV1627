#include "Bullet.h"

Bullet::Bullet(float startX, float startY, float maxRange)
    : shape({ 10.f, 10.f })
{
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::Yellow);
    this->maxRange = maxRange;
    this->startX = startX;
}

void Bullet::Move()
{
    shape.move(moveSpeed, 0.f);  // Move right
    if (shape.getPosition().x - startX >= maxRange) {
        shape.setPosition(-100.f, -100.f);  // Move the bullet offscreen
    }
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
