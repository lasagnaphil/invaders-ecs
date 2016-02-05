//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_SPRITE_H
#define INVADERS_ECS_SPRITE_H

struct Sprite {
    explicit Sprite(std::unique_ptr<sf::Sprite> sprite) : sprite(std::move(sprite)) {}

    std::unique_ptr<sf::Sprite> sprite;
};

#endif //INVADERS_ECS_SPRITE_H
