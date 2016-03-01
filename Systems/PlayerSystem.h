//
// Created by lasagnaphil on 2/9/16.
//

#ifndef INVADERS_ECS_PLAYERSYSTEM_H
#define INVADERS_ECS_PLAYERSYSTEM_H

class PlayerSystem : public ex::System<PlayerSystem>
{
public:
    explicit PlayerSystem()
    {
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Player, Body, PrimitiveShape>([dt](ex::Entity entity, Player& player, Body& body, PrimitiveShape& primitiveShape)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                body.velocity.x = -player.speed;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                body.velocity.x = player.speed;
            else {
                body.velocity.x = 0; body.velocity.y = 0;
            }

        });
    }
private:

};


#endif //INVADERS_ECS_PLAYERSYSTEM_H
