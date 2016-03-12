//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLIDER_H
#define INVADERS_ECS_COLLIDER_H

#include "../Tags.h"

struct Collider {
    explicit Collider(sf::FloatRect rect, ColliderTag tag) : rect(rect), tag(tag) {}
    explicit Collider(sf::FloatRect rect) : Collider(rect, ColliderTag::None) {}

    sf::FloatRect rect;
    ColliderTag tag;
};

#endif //INVADERS_ECS_COLLIDER_H
