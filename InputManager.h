//
// Created by lasagnaphil on 3/9/16.
//

#ifndef INVADERS_ECS_INPUTMANAGER_H
#define INVADERS_ECS_INPUTMANAGER_H

#include <Thor/Input.hpp>

class InputManager
{
public:
    static InputManager& inst()
    {
        static InputManager *inst = new InputManager();
        return *inst;
    }
    explicit InputManager() {
        map["left"] = thor::Action(sf::Keyboard::Left);
        map["right"] = thor::Action(sf::Keyboard::Right);
        map["shoot"] = thor::Action(sf::Keyboard::Space, thor::Action::PressOnce);
        map["quit"] = thor::Action(sf::Event::Closed);
    }

    thor::ActionMap<std::string> map;
};

#endif //INVADERS_ECS_INPUTMANAGER_H
