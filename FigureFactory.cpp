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
//            return new MovableSquare(rand() % 30 + 30);
//        case MovableSquare:
//            return new MovableSquare(30,255);
        case Input:
            string s;
            cout << "Input your own figure:" << endl;
            getline(cin, s);
            return FigureOutOfInput(s);


    }
    return nullptr;
}

Figure *FigureFactory::FigureOutOfInput(string s) {
    Figure *f;
    string t = ParseType(s);
    if (t == "Circle") {
        f = new Circle();
        f->FromString(s);
    }
    else if (t == "Square")
    {
        f = new Square();
        f->FromString(s);
    } else {
        throw exception();
    }
    return f;
}

string FigureFactory::ParseType(string s) {
    return s.substr(0,s.find(':'));
}

Figure *FigureFactory::FigureOutOfType(string s)
{
    if (s == "Circle") {
        return new Circle();
    }
    else if (s == "Square") {
        return new Square();
    }
    else if (s == "MovableSquare")
    {
        return new MovableSquare();
    } else {
        throw exception();
    }
}
