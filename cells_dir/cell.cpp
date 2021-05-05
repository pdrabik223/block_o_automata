//
// Created by pc on 04.05.2021.
//

#include "cell.h"

cell::cell(bool movable, bool hollow) : movable(movable), hollow(hollow) {}

cell::cell():movable(true),hollow(true) {}

bool cell::isMovable() const {
    return movable;
}

bool cell::isHollow() const {
    return hollow;
}

void cell::setMovable(bool movable) {
    cell::movable = movable;
}

void cell::setHollow(bool hollow) {
    cell::hollow = hollow;
}
