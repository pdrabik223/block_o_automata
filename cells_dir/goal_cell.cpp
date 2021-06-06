//
// Created by pc on 05.05.2021.
//

#include "goal_cell.h"
#include "empty_cell.h"
type goal_cell::cell_type = Goal;

goal_cell::goal_cell() : cell(false, true) {}

void goal_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
}

void
goal_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int width) {

    if (plane[curr_pos.reverse(move_dir, width)]->isKillable()) {
        destination[curr_pos.reverse(move_dir, width)] = new empty_cell(true);
        destination[curr_pos.toUint(width)] = new empty_cell(true);
        return;

    } else {

        plane[curr_pos.go(move_dir, width)]->move(plane, destination, move_dir, curr_pos.go(move_dir), width);

        if (*destination[curr_pos.go(move_dir, width)] == Empty) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(width)], destination[curr_pos.go(move_dir, width)]);
        }
    }
}

bool goal_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool goal_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon goal_cell::get_unicode() {

    return {11044, purple};
}

type goal_cell::getCellType() const {
    return cell_type;
}

std::istream &operator>>(std::istream &in, goal_cell &ref) {
    return in;
}

void goal_cell::output_fo_file(std::ostream &out) {
    out <<(int) getCellType();
}

goal_cell *goal_cell::clone() {
    return new goal_cell(*this);
}

