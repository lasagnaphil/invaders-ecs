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
        for (ex::Entity entity : toDestroy) {
            entity.destroy();
        }
        toDestroy.clear();
    }

    void destroy(ex::Entity entity) {
        toDestroy.insert(entity);
    }

    void receive(const CollisionEvent &collision) {
        onCollisionEnter(collision, ColliderTag::Bullet, ColliderTag::TestObject, [this](ex::Entity bullet, ex::Entity testObject){
            destroy(bullet);
            destroy(testObject);
        });
    }

    void onCollisionEnter(const CollisionEvent& collision, const ColliderTag tag1, const ColliderTag tag2,
                            std::function<void(ex::Entity, ex::Entity)> func)
    {
        if (collision.leftTag == tag1 && collision.rightTag == tag2)
            func(collision.left, collision.right);
        else if (collision.leftTag == tag2 && collision.rightTag == tag2)
            func(collision.right, collision.left);
    }


private:
    std::unordered_set<ex::Entity> toDestroy;
};

#endif //INVADERS_ECS_DESTROYSYSTEM_H
