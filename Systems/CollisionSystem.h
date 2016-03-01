//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONSYSTEM_H
#define INVADERS_ECS_COLLISIONSYSTEM_H

class CollisionSystem : public ex::System<CollisionSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        ex::ComponentHandle<Collider> left_collider, right_collider;
        for (ex::Entity left_entity : es.entities_with_components(left_collider)) {
            for (ex::Entity right_entity : es.entities_with_components(right_collider)) {
                printRect(*left_collider->rect);
                printRect(*right_collider->rect);
                if (left_collider->rect->intersects(*right_collider->rect)) {
                    if (left_collider == right_collider) continue;
                    events.emit<CollisionEvent>(left_entity, right_entity);
                }
            }
        }
    }

    void printRect(const sf::FloatRect& rect)
    {
        std::cout << rect.left << " " << rect.top << std::endl;
    }
};

#endif //INVADERS_ECS_COLLISIONSYSTEM_H
