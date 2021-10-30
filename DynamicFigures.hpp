#ifndef DYNAMIC_FIGURES_H
#define DYNAMIC_FIGURES_H

#include "Figure.hpp"
#include "FigureRecord.hpp"
#include <cstddef>


class DynamicFigures
{
private:
    FigureRecord *start_ = NULL;
    FigureRecord *end_ = NULL;
    int size_ = 0;
public:
    void Add(Figure *f);
    void Remove(int i);
    Figure * Get(int i);
    int GetSize();
};

#endif // DYNAMIC_FIGURES_H
