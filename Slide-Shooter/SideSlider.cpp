#include "SideSlider.hpp"

SideSlider::SideSlider() {
    shape_.setSize({ 30, 120 });
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(10, 300);
}

void SideSlider::update(float dt) {
    float speed = 300;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shape_.getPosition().y > 0)
        shape_.move(0, -speed * dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shape_.getPosition().y < 480)
        shape_.move(0, speed * dt);
}

void SideSlider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape_, states);
}
