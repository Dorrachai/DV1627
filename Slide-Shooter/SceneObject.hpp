#pragma once
#include <SFML/Graphics.hpp>

class SceneObject : public sf::Drawable {
public:
    virtual ~SceneObject() = default;
    virtual void update(float dt) = 0;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
