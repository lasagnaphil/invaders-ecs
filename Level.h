//
// Created by lasagnaphil on 3/13/16.
//

#ifndef INVADERS_ECS_LEVEL_H
#define INVADERS_ECS_LEVEL_H

#include <iostream>
#include <memory>
#include <unordered_set>
#include <sstream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

namespace ex = entityx;

#include "Components/Body.h"
#include "Components/Collider.h"
#include "Components/Player.h"
#include "Components/PrimitiveShape.h"
#include "Components/Sprite.h"
#include "Components/Transform.h"

#include "Events/CollisionEvent.h"

#include "Systems/BodySystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/PlayerSystem.h"
#include "Systems/PrimitiveSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/EnemySystem.h"

#include "EntityFactory.h"
#include "InputManager.h"
#include "DestroyManager.h"

using std::cerr;
using std::cout;
using std::endl;

class Level : public ex::EntityX
{
public:
    void start(sf::RenderTarget &target, sf::Font &font);
    void update(ex::TimeDelta dt);
};


#endif //INVADERS_ECS_LEVEL_H
