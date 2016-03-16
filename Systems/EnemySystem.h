//
// Created by lasagnaphil on 3/12/16.
//

#ifndef INVADERS_ECS_ENEMYSYSTEM_H
#define INVADERS_ECS_ENEMYSYSTEM_H

#include "../Constants.h"
#include "../Tags.h"
#include "../Components/Enemy.h"

enum class ChangingDirection { None, Left, Right };

class EnemySystem : public ex::System<EnemySystem>
{
public:
    EnemySystem() : bounds(SCREEN_WIDTH*0.1f, SCREEN_HEIGHT*0.1f, SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f),
                    randEngine(randDevice()), randDist(1, 1000) {}
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override
    {
        es.each<Enemy, Transform>([this, dt](ex::Entity entity, Enemy &enemy, Transform &transform) {
            if (transform.position.x < bounds.left) {
                direction = ChangingDirection::Right;
                transform.position.x = bounds.left + 1.0f;
                std::cout << "Changed direction to right" << std::endl;
            }
            else if (transform.position.x > bounds.left + bounds.width) {
                direction = ChangingDirection::Left;
                transform.position.x = bounds.left + bounds.width - 1.0f;
                std::cout << "Changed direction to left" << std::endl;
            }
        });
        es.each<Enemy, Transform, Body, Collider>(
                [this, &es, dt](ex::Entity entity, Enemy &enemy, Transform &transform, Body &body, Collider &collider) {
            if (direction == ChangingDirection::Left) {
                body.velocity.x = -enemy.speed;
                moveEnemyForward(transform);
            }
            else if (direction == ChangingDirection::Right) {
                body.velocity.x = enemy.speed;
                moveEnemyForward(transform);
            }

            if (enemy.canShoot) {
                int randNum = randDist(randEngine);
                if (randNum <= 10) {
                    EntityFactory::createBullet(es, transform.position + sf::Vector2f(0.0f, collider.rect.height), 300.0f, 10, ColliderTag::EnemyBullet);
                }
            }
        });
        direction = ChangingDirection::None;
    }
    void moveEnemyForward(Transform &transform) {
        transform.position.y += moveForwardLength;
        std::cout << "Moved forward" << std::endl;
    }
private:
    sf::FloatRect bounds;
    ChangingDirection direction = ChangingDirection::None;
    float moveForwardLength = 30.0f;

    std::random_device randDevice;
    std::default_random_engine randEngine;
    std::uniform_int_distribution<int> randDist;

};
#endif //INVADERS_ECS_ENEMYSYSTEM_H
