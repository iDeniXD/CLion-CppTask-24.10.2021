#include "DynamicFigures.hpp"

void DynamicFigures::Add(Figure *f)
{
    FigureRecord *tmp = new FigureRecord;

    tmp->next = NULL;
    tmp->figure = f;

    if (start_ != NULL)
    {
        tmp->prev = end_;
        end_->next = tmp;
        end_ = tmp;
    }
    else
    {
        tmp->prev = NULL;
        start_ = end_ = tmp;
    }

    size_++;
}
void DynamicFigures::Remove(int i)
{
    if(size_ < i)
        return;
    int j = 0;
    FigureRecord *current;
    current = start_;
    for(int j = 0; j < i; j++) {
        current = current->next;
    }
    if (current != end_ && current != start_)
    {
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }
    else
    {
        if (size_ != 1)
        {
            if (current == start_)
            {
                start_ = current->next;
                start_->prev = NULL;
            }
            else
            {
                end_ = current->prev;
                end_->next = NULL;
            }
        }
    }
    delete current;
    current = 0;
    size_--;

}
Figure * DynamicFigures::Get(int i) // Should throw an exception if index is greater than size
{
    int j = 0;
    FigureRecord *current;
    current = start_;
    for(int j = 0; j < i; j++) {
        current = current->next;
    }
    return current->figure;
}
int DynamicFigures::GetSize()
{
    return size_;
}

