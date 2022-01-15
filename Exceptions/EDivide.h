//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EDIVIDE_H
#define TASK0_EDIVIDE_H

#include "EApp.h"
#include "../Figures/Figure.hpp"

struct EDivide : EApp
{
    EDivide();
    ~EDivide() override;
    const char* what() const override;
};

#endif //TASK0_EDIVIDE_H
