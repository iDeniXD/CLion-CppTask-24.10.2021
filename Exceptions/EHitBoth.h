//
// Created by Denis on 23/12/2021.
//

#ifndef TASK0_EHITBOTH_H
#define TASK0_EHITBOTH_H

#include "EApp.h"
#include "../Figure.hpp"
#include "../MovableSquare.h"

struct EHitBoth : EApp
{
    MovableSquare *ms1;
    MovableSquare *ms2;
    EHitBoth(MovableSquare *ms1, MovableSquare *ms2);
    virtual ~EHitBoth();
    virtual const char* what() const;
};

#endif //TASK0_EHITBOTH_H
