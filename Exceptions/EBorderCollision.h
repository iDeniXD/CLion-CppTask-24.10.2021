//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EBORDERCOLLISION_H
#define TASK0_EBORDERCOLLISION_H

#include "EApp.h"

struct EBorderCollision : EApp
{
    enum Border
    {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

    EBorderCollision(Border border);
    ~EBorderCollision() override;

    Border border;
    const char* what() const override;
    virtual const Border &GetBorder();
};

#endif //TASK0_EBORDERCOLLISION_H
