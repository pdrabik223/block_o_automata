//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

barrier_cell::barrier_cell(bool movable) : cell(movable, false) {}

void barrier_cell::show_in_console_unicode() {
    if (movable) std::wcout << cc(gray) << L"\x25A2 ";
    else std::wcout << cc(gray) << L"\x25A3 ";

}

void barrier_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
    return;
}

void
barrier_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                   unsigned int w) {

    if (movable) {
        plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);


        if (*destination[curr_pos.go(move_dir, w)] == t_empty) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
        }
    }

}

bool barrier_cell::operator==(const type& rhs) const {
    return cell_type == rhs;
}

bool barrier_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon barrier_cell::get_unicode() {
    if (movable) return { L"\x25A2 ", gray};
    else return {L"\x25A3 ",gray};
}

type barrier_cell::getCellType() const {
    return cell_type;
}

