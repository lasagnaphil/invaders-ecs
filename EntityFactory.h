//
// Created by lasagnaphil on 3/1/16.
//

#ifndef INVADERS_ECS_ENTITYFACTORY_H
#define INVADERS_ECS_ENTITYFACTORY_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace ex = entityx;

class EntityFactory
{
public:
    static ex::Entity& createPlayer(ex::EntityManager& es);
    static ex::Entity& createBullet(ex::EntityManager& es, sf::Vector2f position, float speed, int damage);
    static ex::Entity& createTestObject(ex::EntityManager& es, sf::Vector2f position, sf::Vector2f velocity);
};


#endif //INVADERS_ECS_ENTITYFACTORY_H
