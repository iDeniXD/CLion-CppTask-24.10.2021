//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EFIGURECOLLISION_H
#define TASK0_EFIGURECOLLISION_H

#include <memory>
#include "EApp.h"
#include "../Figures/Figure.hpp"
#include "../Canvas.hpp"

struct EFigureCollision : EApp
{

    SPFigure* f1;
    SPFigure* f2;

    EFigureCollision(SPFigure* f1, SPFigure* f2);
    ~EFigureCollision() override;

    const char* what() const override;
};

#endif //TASK0_EFIGURECOLLISION_H
