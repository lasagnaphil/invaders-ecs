//
// Created by lasagnaphil on 3/12/16.
//

#ifndef INVADERS_ECS_ENEMYSYSTEM_H
#define INVADERS_ECS_ENEMYSYSTEM_H

#include "../Tags.h"

class EnemySystem : ex::System<EnemySystem>
{
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override
    {

    }
public:
};
#endif //INVADERS_ECS_ENEMYSYSTEM_H
