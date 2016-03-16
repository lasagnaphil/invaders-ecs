//
// Created by lasagnaphil on 2/9/16.
//

#ifndef INVADERS_ECS_PLAYERSYSTEM_H
#define INVADERS_ECS_PLAYERSYSTEM_H

#include "../EntityFactory.h"
#include "../InputManager.h"
#include "../Constants.h"

class PlayerSystem : public ex::System<PlayerSystem>
{
public:
    explicit PlayerSystem()
    {
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Player, Transform, Body, Collider, PrimitiveShape>(
                [dt, &es](ex::Entity entity, Player& player, Transform& transform, Body& body, Collider& collider, PrimitiveShape& primitiveShape)
        {
            if(InputManager::inst().map.isActive("left") && transform.position.x > 0)
                body.velocity.x = -player.speed;
            else if(InputManager::inst().map.isActive("right") && transform.position.x < SCREEN_WIDTH)
                body.velocity.x = player.speed;
            else {
                body.velocity.x = 0; body.velocity.y = 0;
            }

            if(InputManager::inst().map.isActive("shoot")){
                EntityFactory::createBullet(es, transform.position - sf::Vector2f(0.0f, collider.rect.height/2), -300.0f, 3, ColliderTag::PlayerBullet);
            }
        });
    }

private:
};


#endif //INVADERS_ECS_PLAYERSYSTEM_H
