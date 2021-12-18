//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EFIGURECOLLISION_H
#define TASK0_EFIGURECOLLISION_H

#include "EApp.h"
#include "../Figure.hpp"

struct EFigureCollision : EApp
{
    Figure *f1;
    Figure *f2;
    virtual ~EFigureCollision();
    virtual const char* what() const;
};

#endif //TASK0_EFIGURECOLLISION_H
