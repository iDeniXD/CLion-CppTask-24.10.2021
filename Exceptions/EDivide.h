//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EDIVIDE_H
#define TASK0_EDIVIDE_H

#include "EApp.h"
#include "../Figure.hpp"

struct EDivide : EApp
{
    Figure *f;

    virtual ~EDivide();
    virtual const char* what() const;
};

#endif //TASK0_EDIVIDE_H