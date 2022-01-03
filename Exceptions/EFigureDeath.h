//
// Created by Denis on 31/12/2021.
//

#ifndef TASK0_EFIGUREDEATH_H
#define TASK0_EFIGUREDEATH_H

#include "EApp.h"
#include "../Figures/Figure.hpp"

struct EFigureDeath : EApp
{
    Figure *f1;
    Figure *f2;
    EFigureDeath(Figure *f1, Figure *f2 = nullptr);
    EFigureDeath() = default;
    virtual ~EFigureDeath();
    virtual const char* what() const;
};

#endif //TASK0_EFIGUREDEATH_H
