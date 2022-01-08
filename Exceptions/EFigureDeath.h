//
// Created by Denis on 31/12/2021.
//

#ifndef TASK0_EFIGUREDEATH_H
#define TASK0_EFIGUREDEATH_H

#include "EApp.h"
#include "../Figures/Figure.hpp"
#include "../Canvas.hpp"
#include "../Figures/MovableSquare.h"

struct EFigureDeath : EApp
{
    SPFigure* f1 = nullptr;
    SPFigure* f2 = nullptr;
    EFigureDeath(SPFigure *f1);
    EFigureDeath(SPFigure *f1, SPFigure *f2);
    EFigureDeath() = default;
    virtual ~EFigureDeath();
    virtual const char* what() const;
};

#endif //TASK0_EFIGUREDEATH_H
