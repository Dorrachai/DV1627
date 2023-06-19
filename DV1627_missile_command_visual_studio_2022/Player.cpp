#include "Player.hpp"

Player::Player(const sf::Vector2f& position) {
    for (int i = 0; i < 4; i++) {
        m_playerShape[i].setSize(sf::Vector2f(20.f, 20.f));
        m_playerShape[i].setFillColor(sf::Color::White);
    }

    m_playerShape[0].setPosition(position.x, position.y);
    m_playerShape[1].setPosition(position.x, position.y + 20.f);
    m_playerShape[2].setPosition(position.x, position.y + 40.f);
    m_playerShape[3].setPosition(position.x + 20.f, position.y + 20.f);
}


void Player::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            move(0, -23);  // Increased from -10 to -15
        }
        else if (event.key.code == sf::Keyboard::Down) {
            move(0, 23);  // Increased from 10 to 15
        }
    }
}


void Player::update() {
    // For now we leave it empty, later you may add game logic here that needs to update every frame.
}

void Player::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(m_playerShape[i]);
    }
}

void Player::move(float dx, float dy) {  // Add this function
    for (int i = 0; i < 4; i++) {
        m_playerShape[i].move(dx, dy);
    }
}
