//
// Created by lasagnaphil on 3/13/16.
//

#ifndef INVADERS_ECS_SCENENODE_H
#define INVADERS_ECS_SCENENODE_H

#include <vector>

struct SceneNode {
    explicit SceneNode() {}
    explicit SceneNode(std::vector<SceneNode*> nodes) : nodes(nodes) {}

    std::vector<SceneNode*> nodes;
    Body* bodyComponent;
};
#endif //INVADERS_ECS_SCENENODE_H
