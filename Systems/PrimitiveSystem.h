//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_PRIMITIVESYSTEM_H
#define INVADERS_ECS_PRIMITIVESYSTEM_H

class PrimitiveSystem : public ex::System<PrimitiveSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Transform, PrimitiveShape> ([](ex::Entity entity, Transform &transform, PrimitiveShape &primitiveShape) {
            primitiveShape.shape->setPosition(transform.position);
            primitiveShape.shape->setRotation(transform.rotation);
        });
    }
};

#endif //INVADERS_ECS_PRIMITIVESYSTEM_H
