//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_COLLISIONSYSTEM_H
#define INVADERS_ECS_COLLISIONSYSTEM_H

class CollisionSystem : public ex::System<CollisionSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        ex::ComponentHandle<PrimitiveShape> left_shape, right_shape;
        for (ex::Entity left_entity : es.entities_with_components(left_shape)) {
            for (ex::Entity right_entity : es.entities_with_components(right_shape)) {
                if (left_shape->shape->getGlobalBounds().intersects(right_shape->shape->getGlobalBounds())) {
                    if (left_shape == right_shape) continue;
                    events.emit<CollisionEvent>(left_entity, right_entity);
                }
            }
        }
    }
};

#endif //INVADERS_ECS_COLLISIONSYSTEM_H
