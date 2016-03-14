//
// Created by lasagnaphil on 2/9/16.
//

#ifndef INVADERS_ECS_PLAYERSYSTEM_H
#define INVADERS_ECS_PLAYERSYSTEM_H

#include "../EntityFactory.h"
#include "../InputManager.h"

class PlayerSystem : public ex::System<PlayerSystem>
{
public:
    explicit PlayerSystem()
    {
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Player, Transform, Body, PrimitiveShape>([dt, &es](ex::Entity entity, Player& player, Transform& transform, Body& body, PrimitiveShape& primitiveShape)
        {
            if(InputManager::inst().map.isActive("left"))
                body.velocity.x = -player.speed;
            else if(InputManager::inst().map.isActive("right"))
                body.velocity.x = player.speed;
            else {
                body.velocity.x = 0; body.velocity.y = 0;
            }

            if(InputManager::inst().map.isActive("shoot")){
                EntityFactory::createBullet(es, transform.position, -100, 3);
            }
        });
    }

private:
};


#endif //INVADERS_ECS_PLAYERSYSTEM_H
