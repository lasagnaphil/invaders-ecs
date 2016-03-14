//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONSYSTEM_H
#define INVADERS_ECS_COLLISIONSYSTEM_H

#include "../DestroyManager.h"

class CollisionSystem : public ex::System<CollisionSystem>, public ex::Receiver<CollisionSystem>
{
public:
    explicit CollisionSystem() {}
    void configure(ex::EventManager &events) override {
        events.subscribe<CollisionEvent>(*this);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        // update the colliders based on the bodies' position
        es.each<Transform, Collider> ([](ex::Entity entity, Transform &transform, Collider &collider) {
            collider.rect.left = transform.position.x;
            collider.rect.top = transform.position.y;
            std::cout << "body: " << transform.position.x << " " << transform.position.y << std::endl;
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
        event.onCollision(ColliderTag::Bullet, ColliderTag::TestObject, [](ex::Entity bullet, ex::Entity testObject){
            DestroyManager::inst().destroy(bullet);
            DestroyManager::inst().destroy(testObject);
        });
    }


    void printRect(const sf::FloatRect& rect)
    {
        std::cout << rect.left << " " << rect.top << std::endl;
        std::cout << rect.width << " " << rect.height << std::endl;
    }
private:
};

#endif //INVADERS_ECS_COLLISIONSYSTEM_H
