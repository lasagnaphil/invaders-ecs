//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_BODY_H
#define INVADERS_ECS_BODY_H

struct Body {
    Body(const sf::Vector2f &velocity, float angVelocity = 0.0)
            : velocity(velocity), angVelocity(angVelocity) {}
    sf::Vector2f velocity;
    float angVelocity;
};

#endif //INVADERS_ECS_BODY_H
