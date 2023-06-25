#include "Meteor.hpp"

Meteor::Meteor() {
    shape_.setRadius(30);
    shape_.setFillColor(sf::Color::Red);
    shape_.setPosition(800, rand() % 600);
    velocity_ = sf::Vector2f(-100, 0); // Initialize the velocity
}

void Meteor::update(float dt) {
    shape_.move(velocity_ * dt);
}

void Meteor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape_, states);
}
