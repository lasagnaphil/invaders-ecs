//
// Created by lasagnaphil on 3/12/16.
//

#ifndef INVADERS_ECS_ENEMYSYSTEM_H
#define INVADERS_ECS_ENEMYSYSTEM_H

#include "../Tags.h"
#include "../Components/Enemy.h"

class EnemySystem : ex::System<EnemySystem>
{
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override
    {
        es.each<Enemy, Body, PrimitiveShape>([dt](ex::Entity entity, Enemy &enemy, Body &body, PrimitiveShape &primitiveShape) {

        });
    }
public:
    sf::FloatRect bounds;
};
#endif //INVADERS_ECS_ENEMYSYSTEM_H
