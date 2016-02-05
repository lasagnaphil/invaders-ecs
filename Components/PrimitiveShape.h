//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_PRIMITIVESHAPE_H
#define INVADERS_ECS_PRIMITIVESHAPE_H

struct PrimitiveShape {
    explicit PrimitiveShape(std::unique_ptr<sf::Shape> shape) : shape(std::move(shape)) {}

    std::unique_ptr<sf::Shape> shape;
};

#endif //INVADERS_ECS_PRIMITIVESHAPE_H
