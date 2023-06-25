#include "Scene.hpp"

Scene::Scene() {
    objects_.push_back(std::make_unique<SideSlider>());
}

void Scene::update(float dt) {
    for (const auto& object : objects_) {
        object->update(dt);
    }
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& object : objects_) {
        target.draw(*object, states);
    }
}

void Scene::addMeteor() { 
    objects_.push_back(std::make_unique<Meteor>());
}
