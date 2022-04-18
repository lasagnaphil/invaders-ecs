//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_RENDERSYSTEM_H
#define INVADERS_ECS_RENDERSYSTEM_H

#include "../Constants.h"

class RenderSystem : public ex::System<RenderSystem>
{
public:
    explicit RenderSystem(sf::RenderTarget& target, sf::Font &font) : target(target) {
        // inits fps text
        fpsText.setFont(font);
        fpsText.setPosition(2, 2);
        fpsText.setCharacterSize(18);
        fpsText.setColor(sf::Color::White);
        // inits score text
        scoreText.setFont(font);
        scoreText.setPosition(SCREEN_WIDTH * 0.8f, 2);
        scoreText.setCharacterSize(20);
        scoreText.setColor(sf::Color::White);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body, PrimitiveShape>([this](ex::Entity entity, Body &body, PrimitiveShape &renderable) {
            target.draw(*renderable.shape);
        });
        last_update += dt;
        frame_count++;
        // updates fps text every 0.5 seconds
        if (last_update >= 0.5) {
            std::ostringstream fpsOut;
            const double fps = frame_count / last_update;
            fpsOut << es.size() << " entities (" << static_cast<int>(fps) << " fps)";
            fpsText.setString(fpsOut.str());
            last_update = 0.0;
            frame_count = 0.0;
        }
        es.each<Player>([this](ex::Entity entity, Player& player) {
            std::ostringstream scoreOut;
            scoreOut << "Score : " << player.score << "\n" << "Life : " << player.life << "\n"
                     << "Health : " << player.health;
            scoreText.setString(scoreOut.str());
        });
        target.draw(fpsText);
        target.draw(scoreText);
    }

private:
    double last_update = 0.0;
    double frame_count = 0.0;
    sf::RenderTarget &target;
    sf::Text fpsText;
    sf::Text scoreText;
};

#endif //INVADERS_ECS_RENDERSYSTEM_H
