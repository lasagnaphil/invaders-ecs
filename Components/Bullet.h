//
// Created by lasagnaphil on 3/1/16.
//

#ifndef INVADERS_ECS_BULLET_H
#define INVADERS_ECS_BULLET_H


struct Bullet
{
    explicit Bullet(int damage) : damage(damage) {}

    int damage;
};


#endif //INVADERS_ECS_BULLET_H
