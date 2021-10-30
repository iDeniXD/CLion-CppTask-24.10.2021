//
// Created by Denis on 30/10/2021.
//

#include "FigureFactory.h"

#include "Square.hpp"
#include "Circle.hpp"
#include <stdlib.h>
#include <time.h>

Figure *FigureFactory::Create(Type type)
{
    switch(type)
    {
        case RandomCircle:
            return new Circle(rand() % 15 + 15, rand() % 100 + 70);
        case RandomSquare:
            return new Square(rand() % 30 + 30, rand() % 100 + 70);
    }
    return nullptr;
}
