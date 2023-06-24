// SceneObject.h
#pragma once

#include <SFML/Graphics.hpp>

class SceneObject : public sf::Drawable {
public:
    virtual void update(float dt) = 0; // A pure virtual function to update the object.

protected:
    // This function will draw the object.
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
