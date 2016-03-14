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
        es.each<Transform, Body>([dt](ex::Entity entity, Transform &transform, Body &body) {
            transform.position += body.velocity * static_cast<float>(dt);
            transform.rotation += body.angVelocity * dt;
        });
        es.each<SceneNode, Transform>([dt](ex::Entity entity, SceneNode &sceneNode, Transform &transform) {
            for (SceneNode* node : sceneNode.nodes) {
                if (node->connectedTransform!= nullptr)
                    node->connectedTransform->position += transform.position;
            }
        });
    }
};

#endif //INVADERS_ECS_BODYSYSTEM_H
