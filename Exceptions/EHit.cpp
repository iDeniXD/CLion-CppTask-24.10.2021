//
// Created by Denis on 18/12/2021.
//

#include "EHit.h"

EHit::~EHit() {}

const char *EHit::what() const {
    return "MovableFigure is hit";
}

EHit::EHit(MovableSquare *ms, Figure *f):
    ms(ms),
    f(f)
{}
