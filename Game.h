//
// Created by lasagnaphil on 3/13/16.
//

#ifndef INVADERS_ECS_GAME_H
#define INVADERS_ECS_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Thor/Resources.hpp>

#include "Constants.h"
#include "Level.h"

class Game
{
public:
    void start();
    void update();
    void gameLoop();
    void render();

private:
    sf::RenderWindow window;
    thor::ResourceHolder<sf::Font, std::string> fontHolder;
    Level level;
    sf::Clock clock;
};


#endif //INVADERS_ECS_GAME_H
