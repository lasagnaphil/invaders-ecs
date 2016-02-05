//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_RENDERSYSTEM_H
#define INVADERS_ECS_RENDERSYSTEM_H

class RenderSystem : public ex::System<RenderSystem>
{
public:
    explicit RenderSystem(sf::RenderTarget& target, sf::Font &font) : target(target) {
        text.setFont(font);
        text.setPosition(sf::Vector2f(2, 2));
        text.setCharacterSize(18);
        text.setColor(sf::Color::White);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body, PrimitiveShape>([this](ex::Entity entity, Body &body, PrimitiveShape &renderable) {
            target.draw(*renderable.shape.get());
        });
        last_update += dt;
        frame_count++;
        if (last_update >= 0.5) {
            std::ostringstream out;
            const double fps = frame_count / last_update;
            out << es.size() << " entities (" << static_cast<int>(fps) << " fps)";
            text.setString(out.str());
            last_update = 0.0;
            frame_count = 0.0;
        }
        target.draw(text);
    }
private:
    double last_update = 0.0;
    double frame_count = 0.0;
    sf::RenderTarget &target;
    sf::Text text;
};

#endif //INVADERS_ECS_RENDERSYSTEM_H
