//
// Created by Denis on 30/10/2021.
//

#include "FigureFactory.h"

#include "Square.hpp"
#include "Circle.hpp"
#include "MovableSquare.h"
#include "Canvas.hpp"
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
//        case RandomMovable:
//            return new MovableSquare(rand() % 30 + 30, rand() % 100 + 70);
//        case MovableSquare:
//            return new MovableSquare(30,255);
        case Input:
            Figure *f;
            string s;
            cout << "Input your own figure:" << endl;
            getline(cin, s);
            string t = s.substr(0,s.find(':'));
            if (t == "Circle") {
                f = new Circle();
                f->FromString(s);
            }
            else if (t == "Square") // If incorrect type then throw exception
            {
                f = new Square();
                f->FromString(s);
            } else {
                f = FigureFactory::Create(FigureFactory::RandomCircle);
            }
            return f;

    }
    return nullptr;
}
