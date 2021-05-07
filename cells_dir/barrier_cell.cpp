//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

barrier_cell::barrier_cell(bool movable) : cell(movable, false) {}

void barrier_cell::show_in_console_unicode() {
    if (movable) std::wcout << cc(gray) << L"\x25A2 ";
    else std::wcout << cc(gray) << L"\x25A3 ";

}

void barrier_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {
    return;
}

void
barrier_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {

    if (movable) {
        plane[curr_pos.go(move_dir, w)]->move(plane, move_dir, w, curr_pos.go(move_dir));


        if (*plane[curr_pos.go(move_dir, w)] == t_empty) {
            // me                                      the one in front
            std::swap(plane[curr_pos.toUint(w)], plane[curr_pos.go(move_dir, w)]);
        }
    }

}

bool barrier_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool barrier_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

