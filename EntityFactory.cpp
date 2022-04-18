//
// Created by lasagnaphil on 3/1/16.
//


#include "EntityFactory.h"
#include "Components/Body.h"
#include "Components/Collider.h"
#include "Components/PrimitiveShape.h"
#include "Components/Bullet.h"
#include "Components/Player.h"
#include "Components/Transform.h"
#include "Tags.h"
#include "Game.h"

void EntityFactory::createPlayer(ex::EntityManager &es)
{
    ex::Entity entity = es.create();
    entity.assign<Player>(400.0f, 100, 3);
    entity.assign<Transform>(sf::Vector2f(300.0f, 500.0f));
    entity.assign<Body>(sf::Vector2f(0.0f, 0.0f));
    sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
    shape->setFillColor(sf::Color(120, 0, 0));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::Player);
    entity.assign<PrimitiveShape>(shape);
}
void EntityFactory::createBullet(ex::EntityManager& es, sf::Vector2f position, float speed, int damage, ColliderTag tag)
{
    ex::Entity bullet = es.create();
    bullet.assign<Transform>(position);
    bullet.assign<Body>(0.0f, speed);
    sf::Shape* shape = new sf::CircleShape(4);
    shape->setFillColor(sf::Color::Green);
    bullet.assign<Collider>(shape->getLocalBounds(), tag);
    bullet.assign<PrimitiveShape>(shape);
    bullet.assign<Bullet>(damage);
}
void EntityFactory::createTestObject(ex::EntityManager &es, sf::Vector2f position, sf::Vector2f velocity)
{
    ex::Entity entity = es.create();
    entity.assign<Transform>(position);
    entity.assign<Body>(velocity);
    sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
    shape->setFillColor(sf::Color(128, 128, 128));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::TestObject);
    entity.assign<PrimitiveShape>(shape);
}
void EntityFactory::createEnemy(ex::EntityManager &es, sf::Vector2f position, bool canShoot)
{
    ex::Entity entity = es.create();
    entity.assign<Transform>(position);
    entity.assign<Body>(-50.0f, 0.0f);
    sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
    shape->setFillColor(sf::Color(128, 128, 0));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::Enemy);
    entity.assign<PrimitiveShape>(shape);
    entity.assign<Enemy>(50.0f, 10, canShoot);
}
void EntityFactory::createEnemies(ex::EntityManager &es, int width, int height, float xDist, float yDist)
{
    float startPointX = SCREEN_WIDTH / 2 - width * xDist / 2;
    float startPointY = yDist * 2;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            createEnemy(es, sf::Vector2f(startPointX + i * xDist, startPointY + j * yDist), true);
        }
    }
}
