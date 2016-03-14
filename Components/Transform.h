//
// Created by lasagnaphil on 3/14/16.
//

#ifndef INVADERS_ECS_TRANSFORM_H
#define INVADERS_ECS_TRANSFORM_H

struct Transform {
    Transform(sf::Vector2f position, float rotation  = 0.0f) : position(position), rotation(rotation) {}

    sf::Vector2f position;
    float rotation;
};
#endif //INVADERS_ECS_TRANSFORM_H
