//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_FIGUREFACTORY_H
#define TASK0_FIGUREFACTORY_H

class FigureFactory
{
public:
    enum Type
    {
        RandomCircle,
        RandomSquare
    };

    static Figure *Create(Type type);
};

#endif //TASK0_FIGUREFACTORY_H
