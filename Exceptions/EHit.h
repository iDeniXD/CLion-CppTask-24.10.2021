//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EHIT_H
#define TASK0_EHIT_H

#include "EApp.h"
#include "../Figure.hpp"
#include "../MovableSquare.h"

struct EHit : EApp
{
    MovableSquare *ms;
    Figure *f;
    EHit(MovableSquare *ms, Figure *f);
    virtual ~EHit();
    virtual const char* what() const;
};

#endif //TASK0_EHIT_H
