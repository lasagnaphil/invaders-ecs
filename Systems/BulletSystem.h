//
// Created by lasagnaphil on 3/16/16.
//

#ifndef INVADERS_ECS_BULLETSYSTEM_H
#define INVADERS_ECS_BULLETSYSTEM_H

#include "../Constants.h"
#include "../DestroyManager.h"
#include "../Components/Bullet.h"

class BulletSystem : public ex::System<BulletSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {
        es.each<Bullet, Transform> ([](ex::Entity entity, Bullet &bullet, Transform &transform) {
            if (transform.position.y < 0 || transform.position.y > SCREEN_HEIGHT) {
                DestroyManager::inst().destroy(entity);
            }
        });
    }
};

#endif //INVADERS_ECS_BULLETSYSTEM_H
