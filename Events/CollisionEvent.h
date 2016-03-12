//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONEVENT_H
#define INVADERS_ECS_COLLISIONEVENT_H

#include "../Tags.h"

struct CollisionEvent {
    CollisionEvent(ex::Entity left, ex::Entity right, ColliderTag leftTag, ColliderTag rightTag)
            : left(left), right(right), leftTag(leftTag), rightTag(rightTag) {}

    ex::Entity left, right;
    ColliderTag leftTag, rightTag;
};

#endif //INVADERS_ECS_COLLISIONEVENT_H
