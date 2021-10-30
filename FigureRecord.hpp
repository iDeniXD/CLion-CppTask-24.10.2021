#ifndef FIGURERECORD_H
#define FIGURERECORD_H

#include "Figure.hpp"


struct FigureRecord
{
    Figure *figure;
    FigureRecord *next;
    FigureRecord *prev;
};
#endif // FIGURERECORD_H

