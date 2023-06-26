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

    sf::RectangleShape shape;
    float moveSpeed = 0.15f; // adjust this value to make the slider move slower
    std::vector<Bullet> bullets;

    Bullet readyBullet; // this bullet will be visible in front of the slider
    float shootCooldown; // the cooldown time until the player can shoot again
};

#endif
