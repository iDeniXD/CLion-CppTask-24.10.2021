//
// Created by Denis on 18/12/2021.
//

#include "EBorderCollision.h"

EBorderCollision::~EBorderCollision() {}

const char* EBorderCollision::what() const {
    return "Hit the boarder";
}

const EBorderCollision::Border &EBorderCollision::GetBorder() {
    return border;
}
