//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONSYSTEM_H
#define INVADERS_ECS_COLLISIONSYSTEM_H

#include "../DestroyManager.h"
#include "../Components/Bullet.h"

class CollisionSystem : public ex::System<CollisionSystem>, public ex::Receiver<CollisionSystem>
{
public:
    explicit CollisionSystem(ex::EntityManager &es) : es(&es) {}
    void configure(ex::EventManager &events) override {
        events.subscribe<CollisionEvent>(*this);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        // update the colliders based on the bodies' position
        es.each<Transform, Collider> ([](ex::Entity entity, Transform &transform, Collider &collider) {
            collider.rect.left = transform.position.x;
            collider.rect.top = transform.position.y;
            // std::cout << "body: " << transform.position.x << " " << transform.position.y << std::endl;
        });

        // emit collision event
        ex::ComponentHandle<Collider> left_collider, right_collider;
        for (ex::Entity left_entity : es.entities_with_components(left_collider)) {
            for (ex::Entity right_entity : es.entities_with_components(right_collider)) {
                if (left_collider == right_collider) continue;
                if (left_collider->rect.intersects(right_collider->rect)) {
                    events.emit<CollisionEvent>(left_entity, right_entity, left_collider->tag, right_collider->tag);
                }
            }
        }
    }

    void receive(const CollisionEvent &event) {
        event.onCollision(ColliderTag::PlayerBullet, ColliderTag::Enemy, [this](ex::Entity bullet, ex::Entity enemy){
            DestroyManager::inst().destroy(bullet);
            DestroyManager::inst().destroy(enemy);
            es->each<Player>([](ex::Entity entity, Player &player) {
                player.score += 10;
            });
        });
        event.onCollision(ColliderTag::EnemyBullet, ColliderTag::Enemy, [this](ex::Entity bullet, ex::Entity enemy) {
            DestroyManager::inst().destroy(bullet);
        });
        event.onCollision(ColliderTag::EnemyBullet, ColliderTag::Player, [this](ex::Entity bullet, ex::Entity player) {
            DestroyManager::inst().destroy(bullet);
            player.component<Player>()->health -= bullet.component<Bullet>()->damage;
        });
    }


    void printRect(const sf::FloatRect& rect)
    {
        std::cout << rect.left << " " << rect.top << std::endl;
        std::cout << rect.width << " " << rect.height << std::endl;
    }
private:
    ex::EntityManager* es;
};

#endif //INVADERS_ECS_COLLISIONSYSTEM_H
