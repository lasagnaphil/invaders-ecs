//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONEVENT_H
#define INVADERS_ECS_COLLISIONEVENT_H

struct CollisionEvent {
    CollisionEvent(ex::Entity left, ex::Entity right, std::string leftTag, std::string rightTag)
            : left(left), right(right), leftTag(leftTag), rightTag(rightTag) {}

    ex::Entity left, right;
    std::string leftTag, rightTag;
};

#endif //INVADERS_ECS_COLLISIONEVENT_H
