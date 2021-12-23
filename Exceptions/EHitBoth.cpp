//
// Created by Denis on 23/12/2021.
//

#include "EHitBoth.h"

EHitBoth::~EHitBoth() {}

const char *EHitBoth::what() const {
    return "Two Movable Figures have just collapsed";
}

EHitBoth::EHitBoth(MovableSquare *ms1, MovableSquare *ms2):
        ms1(ms1),
        ms2(ms2)
{}

