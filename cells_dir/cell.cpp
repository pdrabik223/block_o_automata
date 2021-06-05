//
// Created by pc on 04.05.2021.
//

#include "cell.h"
type cell::cell_type = Cell;
cell::cell(bool movable, bool killable) : movable(movable), killable(killable) {

}

cell::cell(): movable(true), killable(true) {}

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

bool cell::operator==(const type& rhs) const {
    return cell_type == rhs;
}

bool cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

type cell::getCellType() const {
    return cell_type;
}

