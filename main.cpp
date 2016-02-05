#include <iostream>
#include <memory>
#include <unordered_set>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include <sstream>

namespace ex = entityx;

#include "Components/Body.h"
#include "Components/Collider.h"
#include "Components/PrimitiveShape.h"
#include "Components/Sprite.h"

#include "Events/CollisionEvent.h"

#include "Systems/BodySystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/DestroySystem.h"
#include "Systems/PrimitiveSystem.h"
#include "Systems/RenderSystem.h"

using std::cerr;
using std::cout;
using std::endl;




class Level : public ex::EntityX {
public:
    explicit Level(sf::RenderTarget &target, sf::Font &font) {
        // initialize the systems
        systems.add<BodySystem>();
        systems.add<PrimitiveSystem>();
        systems.add<CollisionSystem>();
        systems.add<DestroySystem>();
        systems.add<RenderSystem>(target, font);
        systems.configure();

        // create the entities
        for(int i = 0; i < 10; i++) {
            ex::Entity entity = entities.create();
            entity.assign<Body>(sf::Vector2f(100.0f, 100.0f + 40.0f * i), sf::Vector2f(0.0f, 10.0f * (10-i)));
            std::unique_ptr<sf::RectangleShape> shape(new sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)));
            shape->setFillColor(sf::Color(128, 128, 128));
            entity.assign<PrimitiveShape>(std::move(shape));
        }
    }

    void update(ex::TimeDelta dt) {
        systems.update<BodySystem>(dt);
        systems.update<PrimitiveSystem>(dt);
        systems.update<CollisionSystem>(dt);
        systems.update<DestroySystem>(dt);
        systems.update<RenderSystem>(dt);
    }
};

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Invaders - ECS", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::Font font;
    if (!font.loadFromFile("LiberationSans-Regular.ttf")) {
        cerr << "error: failed to load LiberationSans-Regular.ttf" << endl;
        return 1;
    }

    Level level(window, font);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();
        sf::Time elapsed = clock.restart();
        level.update(elapsed.asSeconds());
        window.display();
    }
    return 0;
}