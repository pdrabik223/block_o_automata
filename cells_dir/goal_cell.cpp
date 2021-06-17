//
// Created by pc on 05.05.2021.
//

#include "goal_cell.h"
#include "EmptyCell.h"
Type GoalCell::cell_type_ = GOAL;

GoalCell::GoalCell() : Cell(false, true) {}

void GoalCell::Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) {
}

void GoalCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int width) {

    if (plane[curr_pos.reverse(move_dir, width)]->IsKillable()) {
        destination[curr_pos.reverse(move_dir, width)] = new EmptyCell(true);
        destination[curr_pos.toUint(width)] = new EmptyCell(true);
        return;

    } else {

      plane[curr_pos.go(move_dir, width)]->Move(plane, destination, move_dir,
                                                curr_pos.go(move_dir), width);

        if (*destination[curr_pos.go(move_dir, width)] == EMPTY) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(width)], destination[curr_pos.go(move_dir, width)]);
        }
    }
}

bool GoalCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool GoalCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

icon GoalCell::GetUnicode() {

    return {11044, purple};
}

Type GoalCell::GetCellType() const {
    return cell_type_;
}

std::istream &operator>>(std::istream &in, GoalCell &ref) {
    return in;
}

void GoalCell::OutputFoFile(std::ostream &out) {
    out <<(int)GetCellType();
}

GoalCell *GoalCell::Clone() {
    return new GoalCell(*this);
}

