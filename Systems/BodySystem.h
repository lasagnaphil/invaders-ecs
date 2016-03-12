//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_BODYSYSTEM_H
#define INVADERS_ECS_BODYSYSTEM_H

#include "../Components/SceneNode.h"

class BodySystem : public ex::System<BodySystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body>([dt](ex::Entity entity, Body &body) {
            body.position += body.velocity * static_cast<float>(dt);
            body.rotation += body.angVelocity * dt;
        });
        es.each<SceneNode, Body>([dt](ex::Entity entity, SceneNode &sceneNode, Body &body) {
            for (SceneNode* node : sceneNode.nodes) {
                if (node->bodyComponent != nullptr)
                    node->bodyComponent->position += body.position;
            }
        });
    }
};

#endif //INVADERS_ECS_BODYSYSTEM_H
