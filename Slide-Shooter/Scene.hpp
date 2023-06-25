#pragma once
#include "SideSlider.hpp"
#include "Meteor.hpp"
#include <vector>
#include <memory>

class Scene {
private:
    std::vector<std::unique_ptr<SceneObject>> objects_;

public:
    Scene();
    void update(float dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void addMeteor(); 
};
