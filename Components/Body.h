//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_BODY_H
#define INVADERS_ECS_BODY_H

struct Body {
    explicit Body(const sf::Vector2f &velocity = sf::Vector2f(), float angVelocity = 0.0f)
            : velocity(velocity), angVelocity(angVelocity) {}
    explicit Body(float velX, float velY, float angVelocity = 0.0f)
            : velocity(velX, velY), angVelocity(angVelocity) {}

    sf::Vector2f velocity;
    float angVelocity;
};

#endif //INVADERS_ECS_BODY_H
