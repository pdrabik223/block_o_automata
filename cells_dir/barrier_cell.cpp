//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

Type BarrierCell::cell_type_ = BARRIER;

BarrierCell::BarrierCell() : Cell(false, false) {}

BarrierCell::BarrierCell(bool movable) : Cell(movable, false) {}

void BarrierCell::Action(const std::vector<Cell *> &plane, unsigned w,
                         coord curr_pos, std::vector<Cell *> &destination) {}

void BarrierCell::Move(const std::vector<Cell *> &plane,
                       std::vector<Cell *> &destination, direction move_dir,
                       coord curr_pos, unsigned int width) {

  if (!movable_)
    return;

  plane[curr_pos.go(move_dir, width)]->Move(plane, destination, move_dir,
                                            curr_pos.go(move_dir), width);

  if (*destination[curr_pos.go(move_dir, width)] == EMPTY) {
    // me                                      the one in front
    std::swap(destination[curr_pos.toUint(width)],
              destination[curr_pos.go(move_dir, width)]);
  }
}

bool BarrierCell::operator==(const Type &rhs) const {
  return cell_type_ == rhs;
}

bool BarrierCell::operator!=(const Type &rhs) const {
  return cell_type_ != rhs;
}

icon BarrierCell::GetUnicode() {
  if (movable_)
    return {9634, gray};
  else
    return {9635, gray};
}

Type BarrierCell::GetCellType() const { return cell_type_; }

void BarrierCell::OutputFoFile(std::ostream &out) {
  out << (int)GetCellType();
  out << " ";
  out << IsMovable();
}

BarrierCell *BarrierCell::Clone() { return new BarrierCell(*this); }
