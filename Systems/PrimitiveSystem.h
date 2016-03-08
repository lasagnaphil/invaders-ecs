//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_PRIMITIVESYSTEM_H
#define INVADERS_ECS_PRIMITIVESYSTEM_H

class PrimitiveSystem : public ex::System<PrimitiveSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body, PrimitiveShape> ([](ex::Entity entity, Body &body, PrimitiveShape &primitiveShape) {
            primitiveShape.shape->setPosition(body.position);
            primitiveShape.shape->setRotation(body.rotation);
        });
    }
};

#endif //INVADERS_ECS_PRIMITIVESYSTEM_H
