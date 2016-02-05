//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONEVENT_H
#define INVADERS_ECS_COLLISIONEVENT_H

struct CollisionEvent {
    CollisionEvent(ex::Entity left, ex::Entity right) : left(left), right(right) {}

    ex::Entity left, right;
};

#endif //INVADERS_ECS_COLLISIONEVENT_H
