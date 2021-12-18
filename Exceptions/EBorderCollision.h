//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EBORDERCOLLISION_H
#define TASK0_EBORDERCOLLISION_H

#include "EApp.h"

struct EBorderCollision : EApp
{
    ~EBorderCollision();

    enum Border
    {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };
    Border border;
    virtual const char* what() const;
    virtual const Border &GetBorder();
};

#endif //TASK0_EBORDERCOLLISION_H
