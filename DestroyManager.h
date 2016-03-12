//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_DESTROYSYSTEM_H
#define INVADERS_ECS_DESTROYSYSTEM_H

class DestroyManager
{
public:
    static DestroyManager& inst()
    {
        static DestroyManager *inst = new DestroyManager();
        return *inst;
    }

    void update(ex::TimeDelta dt) {
        for (ex::Entity entity : toDestroy) {
            entity.destroy();
        }
        toDestroy.clear();
    }

    void destroy(ex::Entity entity) {
        toDestroy.insert(entity);
    }

private:
    std::unordered_set<ex::Entity> toDestroy;
};

#endif //INVADERS_ECS_DESTROYSYSTEM_H
