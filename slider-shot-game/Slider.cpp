#include "Slider.h"

Slider::Slider(float x, float y)
    : shape({ 20.f, 60.f }), readyBullet(x + 20.f, y + 30.f, 0.f)
{
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);
    shootCooldown = 0.f;
}

void Slider::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
    if (shootCooldown <= 0.f)
    {
        readyBullet.Draw(window);
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}

void Slider::Shoot(float maxRange)
{
    if (shootCooldown <= 0.f)
    {
        bullets.push_back(readyBullet);
        readyBullet = Bullet(shape.getPosition().x + shape.getSize().x, shape.getPosition().y + shape.getSize().y / 2, maxRange);
        shootCooldown = 1.f;
    }
}

void Slider::UpdateReadyBullet()
{
    readyBullet.shape.setPosition(shape.getPosition().x + shape.getSize().x, shape.getPosition().y + shape.getSize().y / 2);
}

void Slider::MoveUp()
{
    shape.move(0.f, -moveSpeed);
}

void Slider::MoveDown()
{
    shape.move(0.f, moveSpeed);
}
