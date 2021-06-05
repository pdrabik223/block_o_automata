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
                unsigned int w) {

    if (plane[curr_pos.reverse(move_dir, w)]->isKillable()) {
        destination[curr_pos.reverse(move_dir, w)] = new empty_cell(true);
        destination[curr_pos.toUint(w)] = new empty_cell(true);
        return;

    } else {

        plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);

        if (*destination[curr_pos.go(move_dir, w)] == Empty) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
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

