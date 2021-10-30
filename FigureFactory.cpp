//
// Created by Denis on 30/10/2021.
//

#include "FigureFactory.h"

#include "Square.hpp"
#include "Circle.hpp"
#include <stdlib.h>
#include <time.h>

int *FigureFactory::Create(Type type)
{
    switch(type)
    {
        case RandomCircle:
            return new Circle(rand() % 100, rand() % 254);
        case RandomSquare:
            return new Square(rand() % 100, rand() % 254);
    }
}
