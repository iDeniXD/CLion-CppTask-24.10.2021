//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_FIGUREFACTORY_H
#define TASK0_FIGUREFACTORY_H

#include "Figure.hpp"

class FigureFactory
{
public:
    enum Type
    {
        RandomCircle,
        RandomSquare,
        Input
    };

    static Figure *Create(Type type);
};

#endif //TASK0_FIGUREFACTORY_H
