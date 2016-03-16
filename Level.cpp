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
    systems.add<EnemySystem>();
    systems.add<PlayerSystem>();
    systems.add<BulletSystem>();
    systems.configure();

    // create the player
    EntityFactory::createPlayer(entities);

    // create the entities
    EntityFactory::createEnemies(entities, 10, 5, 50.0f, 50.0f);
}

void Level::update(ex::TimeDelta dt)
{
    systems.update<BodySystem>(dt);
    systems.update<PrimitiveSystem>(dt);
    systems.update<CollisionSystem>(dt);
    systems.update<RenderSystem>(dt);
    systems.update<EnemySystem>(dt);
    systems.update<PlayerSystem>(dt);
    systems.update<BulletSystem>(dt);

    DestroyManager::inst().update(dt);
}