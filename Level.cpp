//
// Created by lasagnaphil on 3/13/16.
//

#include "Level.h"

void Level::start(sf::RenderTarget &target, sf::Font &font)
{
    systems.add<BodySystem>();
    systems.add<PrimitiveSystem>();
    systems.add<CollisionSystem>();
    systems.add<RenderSystem>(target, font);

    systems.add<PlayerSystem>();
    systems.configure();

    // create the player
    EntityFactory::createPlayer(entities);

    // create the entities
    for(int i = 0; i < 10; i++) {
        EntityFactory::createTestObject(entities, sf::Vector2f(100.0f, 100.0f + 40.0f * i), sf::Vector2f(0.0f, 10.0f * (10-i)));
    }
}

void Level::update(ex::TimeDelta dt)
{
    systems.update<BodySystem>(dt);
    systems.update<PrimitiveSystem>(dt);
    systems.update<CollisionSystem>(dt);
    systems.update<RenderSystem>(dt);

    systems.update<PlayerSystem>(dt);

    DestroyManager::inst().update(dt);
}