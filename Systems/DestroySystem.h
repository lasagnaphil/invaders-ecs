//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_DESTROYSYSTEM_H
#define INVADERS_ECS_DESTROYSYSTEM_H

class DestroySystem : public ex::System<DestroySystem>, public ex::Receiver<DestroySystem>
{
public:
    void configure(ex::EventManager &events) override {
        events.subscribe<CollisionEvent>(*this);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        for (ex::Entity entity : collided) {
            entity.destroy();
        }
        collided.clear();
    }

    void receive(const CollisionEvent &collision) {
        collided.insert(collision.left);
        collided.insert(collision.right);
    }

private:
    std::unordered_set<ex::Entity> collided;
};

#endif //INVADERS_ECS_DESTROYSYSTEM_H
