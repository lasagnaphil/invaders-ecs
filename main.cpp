#include <iostream>
#include <memory>
#include <unordered_set>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include <sstream>

using std::cerr;
using std::cout;
using std::endl;

namespace ex = entityx;

struct Body {
    Body(const sf::Vector2f &position, const sf::Vector2f &velocity, float angVelocity = 0.0)
            :position(position), velocity(velocity), angVelocity(angVelocity) {}
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation = 0.0;
    float angVelocity;
};

struct PrimitiveShape {
    explicit PrimitiveShape(std::unique_ptr<sf::Shape> shape) : shape(std::move(shape)) {}

    std::unique_ptr<sf::Shape> shape;
};

struct Sprite {
    explicit Sprite(std::unique_ptr<sf::Sprite> sprite) : sprite(std::move(sprite)) {}

    std::unique_ptr<sf::Sprite> sprite;
};

struct Collider {
    explicit Collider(sf::FloatRect rect) : rect(rect) {}

    sf::FloatRect rect;
};

struct CollisionEvent {
    CollisionEvent(ex::Entity left, ex::Entity right) : left(left), right(right) {}

    ex::Entity left, right;
};

class BodySystem : public ex::System<BodySystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        es.each<Body>([dt](ex::Entity entity, Body &body) {
            body.position += body.velocity * static_cast<float>(dt);
            body.rotation += body.angVelocity * dt;
        });
    }
};

class CollisionSystem : public ex::System<CollisionSystem>
{
public:
    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        ex::ComponentHandle<Collider> left_collider, right_collider;
        for (ex::Entity left_entity : es.entities_with_components(left_collider)) {
            for (ex::Entity right_entity : es.entities_with_components(right_collider)) {
                if (left_collider->rect.intersects(right_collider->rect)) {
                    events.emit<CollisionEvent>(left_entity, right_entity);
                }
            }
        }
    }
};

class DestroySystem : public ex::System<DestroySystem>, public ex::Receiver<DestroySystem>
{
public:
    void configure(ex::EventManager &events) override {
        events.subscribe<CollisionEvent>(*this);
    }

    void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
        for (ex::Entity entity : collided) {
            entity.destroy();
        }
        collided.clear();
    }

    void receive(const CollisionEvent &collision) {
        collided.insert(collision.left);
        collided.insert(collision.right);
    }

private:
    std::unordered_set<ex::Entity> collided;
};

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
            renderable.shape->setPosition(body.position);
            renderable.shape->setRotation(body.rotation);
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

class Level : public ex::EntityX {
public:
    explicit Level(sf::RenderTarget &target, sf::Font &font) {
        // initialize the systems
        systems.add<BodySystem>();
        systems.add<CollisionSystem>();
        systems.add<DestroySystem>();
        systems.add<RenderSystem>(target, font);
        systems.configure();

        // create the entities
        for(int i = 0; i < 10; i++) {
            ex::Entity entity = entities.create();
            entity.assign<Body>(sf::Vector2f(100.0f, 100.0f + 40.0f * i), sf::Vector2f(0.0f, 10.0f * (5-i)));
            std::unique_ptr<sf::RectangleShape> shape(new sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)));
            shape->setFillColor(sf::Color(128, 128, 128));
            sf::FloatRect rect = shape->getLocalBounds();
            entity.assign<PrimitiveShape>(std::move(shape));
            //entity.assign<Collider>(rect);
        }
    }

    void update(ex::TimeDelta dt) {
        systems.update<BodySystem>(dt);
        systems.update<CollisionSystem>(dt);
        systems.update<DestroySystem>(dt);
        systems.update<RenderSystem>(dt);
    }
};

int main() {

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Invaders - ECS", sf::Style::Default);
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