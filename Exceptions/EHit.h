//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EHIT_H
#define TASK0_EHIT_H

#include "EApp.h"

struct EHit : EApp
{
    virtual ~EHit();
    virtual const char* what() const;
};

#endif //TASK0_EHIT_H
