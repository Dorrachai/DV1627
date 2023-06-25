#pragma once
#include "SceneObject.hpp"
#include <SFML/Graphics.hpp>

class SideSlider : public SceneObject {
private:
    sf::RectangleShape shape_;

public:
    SideSlider();
    void update(float dt) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
