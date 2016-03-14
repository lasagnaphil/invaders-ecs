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

ex::Entity& EntityFactory::createPlayer(ex::EntityManager &es)
{
    ex::Entity entity = es.create();
    entity.assign<Player>(400.0f, 100, 3);
    entity.assign<Transform>(sf::Vector2f(300.0f, 500.0f));
    entity.assign<Body>(sf::Vector2f(0.0f, 0.0f));
    std::unique_ptr<sf::RectangleShape> shape(new sf::RectangleShape(sf::Vector2f(20.0f, 20.0f)));
    shape->setFillColor(sf::Color(120, 0, 0));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::Player);
    entity.assign<PrimitiveShape>(std::move(shape));
}
ex::Entity& EntityFactory::createBullet(ex::EntityManager& es, sf::Vector2f position, float speed, int damage)
{
    ex::Entity bullet = es.create();
    bullet.assign<Transform>(position);
    bullet.assign<Body>(sf::Vector2f(0.0f, speed));
    std::unique_ptr<sf::CircleShape> shape(new sf::CircleShape(4));
    shape->setFillColor(sf::Color::Green);
    bullet.assign<Collider>(shape->getLocalBounds(), ColliderTag::Bullet);
    bullet.assign<PrimitiveShape>(std::move(shape));
    bullet.assign<Bullet>(damage);
}
ex::Entity &EntityFactory::createTestObject(ex::EntityManager &es, sf::Vector2f position, sf::Vector2f velocity)
{
    ex::Entity entity = es.create();
    entity.assign<Transform>(position);
    entity.assign<Body>(velocity);
    std::unique_ptr<sf::RectangleShape> shape(new sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)));
    shape->setFillColor(sf::Color(128, 128, 128));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::TestObject);
    entity.assign<PrimitiveShape>(std::move(shape));
}

ex::Entity &EntityFactory::createEnemy(ex::EntityManager &es, sf::Vector2f position)
{
    ex::Entity entity = es.create();
    entity.assign<Transform>(position);
    entity.assign<Body>(sf::Vector2f(0.0f, 0.0f));
    std::unique_ptr<sf::RectangleShape> shape(new sf::RectangleShape(sf::Vector2f(20.0f, 20.0f)));
    shape->setFillColor(sf::Color(128, 128, 0));
    entity.assign<Collider>(shape->getLocalBounds(), ColliderTag::Enemy);
    entity.assign<PrimitiveShape>(std::move(shape));
}
