//
// Created by pc on 04.05.2021.
//

#include "cell.h"

cell::cell(bool movable, bool killable) : movable(movable), killable(killable), local_creation_time(creation_order) {
    ++creation_order;
}

cell::cell(): movable(true), killable(true), local_creation_time(creation_order) {
        ++creation_order;
}

bool cell::isMovable() const {
    return movable;
}

bool cell::isKillable() const {
    return killable;
}

void cell::setMovable(bool movable) {
    cell::movable = movable;
}


void cell::setKillable(bool killable) {
    cell::killable = killable;
}

bool cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

