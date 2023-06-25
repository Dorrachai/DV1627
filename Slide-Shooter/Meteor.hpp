#pragma once
#include "SceneObject.hpp"
#include <SFML/Graphics.hpp>

class Meteor : public SceneObject {
private:
    sf::CircleShape shape_;
    sf::Vector2f velocity_; // Add this line

public:
    Meteor();
    void update(float dt) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
