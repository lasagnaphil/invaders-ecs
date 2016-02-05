//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLIDER_H
#define INVADERS_ECS_COLLIDER_H

struct Collider {
    explicit Collider(sf::FloatRect rect) : rect(rect) {}

    sf::FloatRect rect;
};

#endif //INVADERS_ECS_COLLIDER_H
