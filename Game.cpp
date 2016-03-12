//
// Created by lasagnaphil on 3/13/16.
//

#include "Game.h"

void Game::start()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Invaders - ECS", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    try {
        fontHolder.acquire("LiberationSans", thor::Resources::fromFile<sf::Font>("LiberationSans-Regular.ttf"));
    }
    catch (thor::ResourceLoadingException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    level.start(window, fontHolder["LiberationSans"]);

    gameLoop();
}

void Game::gameLoop()
{
    while (window.isOpen()) {

    sf::Event event;

    InputManager::inst().map.update(window);
    if (InputManager::inst().map.isActive("quit"))
        window.close();

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
    update();
    render();
    }
}
void Game::update()
{
    sf::Time elapsed = clock.restart();
    level.update(elapsed.asSeconds());
}
void Game::render()
{
    window.display();
}
