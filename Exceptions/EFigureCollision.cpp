//
// Created by Denis on 18/12/2021.
//

#include "EFigureCollision.h"

EFigureCollision::EFigureCollision(SPFigure* f1, SPFigure* f2) :
    f1(f1),
    f2(f2)
{}
EFigureCollision::~EFigureCollision() {}

const char *EFigureCollision::what() const {
    return "Collision of two figures";
}

