//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONEVENT_H
#define INVADERS_ECS_COLLISIONEVENT_H

#include "../Tags.h"

struct CollisionEvent {
    CollisionEvent(ex::Entity left, ex::Entity right, ColliderTag leftTag, ColliderTag rightTag)
            : left(left), right(right), leftTag(leftTag), rightTag(rightTag) {}

    mutable ex::Entity left, right;
    ColliderTag leftTag, rightTag;

    void onCollision(const ColliderTag tag1, const ColliderTag tag2,
                            std::function<void(ex::Entity, ex::Entity)> func) const
    {
        if (this->leftTag == tag1 && this->rightTag == tag2)
            func(this->left, this->right);
        else if (this->leftTag == tag2 && this->rightTag == tag2)
            func(this->right, this->left);
    }
};

#endif //INVADERS_ECS_COLLISIONEVENT_H
