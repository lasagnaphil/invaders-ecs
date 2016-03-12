//
// Created by lasagnaphil on 3/12/16.
//

#ifndef INVADERS_ECS_ENEMY_H
#define INVADERS_ECS_ENEMY_H

struct Enemy
{
    explicit Enemy(int speed, int damage, bool canShoot) : speed(speed), damage(damage), canShoot(canShoot)
    {

    }
    int speed;
    int damage;
    bool canShoot;
};
#endif //INVADERS_ECS_ENEMY_H
