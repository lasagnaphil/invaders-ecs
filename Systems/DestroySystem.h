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

    void receive(const CollisionEvent &collision) {
        onCollisionEnter(collision, "bullet", "test_object", [this](ex::Entity bullet, ex::Entity testObject){
            toDestroy.insert(bullet);
            toDestroy.insert(testObject);
        });
    }

    void onCollisionEnter(const CollisionEvent& collision, const std::string& tag1, const std::string& tag2,
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
