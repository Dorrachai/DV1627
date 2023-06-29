#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Slider {
public:
    Slider(float x, float y);
    void Draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    void Shoot(float maxRange);
    void UpdateReadyBullet();
    void DecreaseHealth();

    sf::RectangleShape shape;
    float moveSpeed = 0.15f;
    std::vector<Bullet> bullets;

    Bullet readyBullet;
    float shootCooldown;
    int playerHealth = 3;
};

#endif
