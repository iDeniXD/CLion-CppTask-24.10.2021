//
// Created by Denis on 31/12/2021.
//

#include "EFigureDeath.h"
EFigureDeath::EFigureDeath(SPFigure *f1) :
        f1(f1)
{}
EFigureDeath::EFigureDeath(SPFigure *f1, SPFigure *f2) :
        f1(f1),
        f2(f2)
{}

EFigureDeath::~EFigureDeath() {}

const char *EFigureDeath::what() const {
    return "Some figures are going to die";
}

