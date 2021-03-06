//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_FIGUREFACTORY_H
#define TASK0_FIGUREFACTORY_H

#include "../Figures/Figure.hpp"
#include "list"

class FigureFactory
{
public:
    enum Type
    {
        RandomCircle,
        RandomSquare,
        RandomMovable,
        Input
    };

    static list<Figure *> Create(initializer_list<Type> types);

    static Figure *Create(Type type);

    static Figure *FigureOutOfInput(string basicString);

    static string ParseType(string basicString);

    static Figure *FigureOutOfType(string s);
};

#endif //TASK0_FIGUREFACTORY_H
