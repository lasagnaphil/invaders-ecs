//
// Created by lasagnaphil on 3/9/16.
//

#ifndef INVADERS_ECS_INPUTMANAGER_H
#define INVADERS_ECS_INPUTMANAGER_H

#include <Thor/Input.hpp>

class InputManager
{
public:
    static InputManager *_inst;
    explicit InputManager() {
        map["left"] = thor::Action(sf::Keyboard::Left);
        map["right"] = thor::Action(sf::Keyboard::Right);
        map["shoot"] = thor::Action(sf::Keyboard::Space, thor::Action::PressOnce);
    }
    static InputManager *inst() {
        if (!_inst)
            _inst = new InputManager;
        return _inst;
    }

    thor::ActionMap<std::string> map;
};

InputManager *InputManager::_inst = 0;

#endif //INVADERS_ECS_INPUTMANAGER_H
