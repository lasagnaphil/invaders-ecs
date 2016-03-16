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
    static void createPlayer(ex::EntityManager& es);
    static void createBullet(ex::EntityManager& es, sf::Vector2f position, float speed, int damage);
    static void createTestObject(ex::EntityManager& es, sf::Vector2f position, sf::Vector2f velocity);
    static void createEnemy(ex::EntityManager& es, sf::Vector2f position, bool canShoot);
    static void createEnemies(ex::EntityManager& es, int width, int height, float xDist, float yDist);
};


#endif //INVADERS_ECS_ENTITYFACTORY_H
