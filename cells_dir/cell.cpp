//
// Created by pc on 04.05.2021.
//

#include "cell.h"
Type Cell::cell_type_ = CELL;
Cell::Cell(bool movable, bool killable)
    : movable_(movable), killable_(killable) {}

Cell::Cell() : movable_(true), killable_(true) {}

bool Cell::IsMovable() const { return movable_; }

bool Cell::IsKillable() const { return killable_; }

void Cell::SetMovable(bool movable) { Cell::movable_ = movable; }

void Cell::SetKillable(bool killable) { Cell::killable_ = killable; }

bool Cell::operator==(const Type &rhs) const { return cell_type_ == rhs; }

bool Cell::operator!=(const Type &rhs) const { return cell_type_ != rhs; }

Type Cell::GetCellType() const { return cell_type_; }
