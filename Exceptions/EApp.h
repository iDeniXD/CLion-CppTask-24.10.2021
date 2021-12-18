//
// Created by Denis on 18/12/2021.
//

#ifndef TASK0_EAPP_H
#define TASK0_EAPP_H

using namespace std;
#include "iostream"

struct EApp
{
    virtual ~EApp();
    virtual const char* what() const;
};

#endif //TASK0_EAPP_H
