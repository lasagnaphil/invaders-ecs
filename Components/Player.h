//
// Created by lasagnaphil on 2/9/16.
//

#ifndef INVADERS_ECS_PLAYER_H
#define INVADERS_ECS_PLAYER_H

struct Player
{
public:
    Player(float speed, int health, int life) : speed(speed), health(health), life(life)
    {

    }
    float speed;
    int health;
    int life;
};


#endif //INVADERS_ECS_PLAYER_H
