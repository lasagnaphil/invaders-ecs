//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLIDER_H
#define INVADERS_ECS_COLLIDER_H

struct Collider {
    explicit Collider(sf::FloatRect rect, std::string tag) : rect(rect), tag(tag) {}
    explicit Collider(sf::FloatRect rect) : Collider(rect, "none") {}

    sf::FloatRect rect;
    std::string tag;
};

#endif //INVADERS_ECS_COLLIDER_H
