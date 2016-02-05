//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_BODYSYSTEM_H
#define INVADERS_ECS_BODYSYSTEM_H

class BodySystem : public ex::System<BodySystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body>([dt](ex::Entity entity, Body &body) {
            body.position += body.velocity * static_cast<float>(dt);
            body.rotation += body.angVelocity * dt;
        });
    }
};

#endif //INVADERS_ECS_BODYSYSTEM_H
