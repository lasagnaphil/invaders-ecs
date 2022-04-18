//
// Created by lasagnaphil on 2/6/16.
//

#ifndef INVADERS_ECS_PRIMITIVESHAPE_H
#define INVADERS_ECS_PRIMITIVESHAPE_H

struct PrimitiveShape {
    explicit PrimitiveShape(sf::Shape* shape) : shape(shape) {}

    sf::Shape* shape;
};

#endif //INVADERS_ECS_PRIMITIVESHAPE_H
