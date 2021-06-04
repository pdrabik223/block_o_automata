//
// Created by pc on 04.05.2021.
//

#include "kill_cell.h"
#include "empty_cell.h"

kill_cell::kill_cell() : cell(false, true) {}

void kill_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {

}

void
kill_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int w) {
    if (plane[curr_pos.reverse(move_dir, w)]->isKillable()) {
        destination[curr_pos.reverse(move_dir, w)] = new empty_cell(false);

        return;
    } else {

        plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);

        if (*destination[curr_pos.go(move_dir, w)] == Empty) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
        }
    }

}

bool kill_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool kill_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon kill_cell::get_unicode() {
    return {10006, red};
}

type kill_cell::getCellType() const {
    return cell_type;
}

void kill_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();

}



