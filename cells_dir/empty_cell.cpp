//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

empty_cell::empty_cell( bool locked) : cell(false, true), locked(locked) {}

void empty_cell::show_in_console_unicode() {
    if(locked)std::wcout<<"  ";
    else std::wcout<<cc(gray)<<L"\x2022 ";
}

void empty_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {}

void empty_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {

    if(*plane[curr_pos.go(move_dir,w)] == t_empty){
        // me                                      the one in front
        std::swap(plane[curr_pos.toUint(w)] ,plane[curr_pos.go(move_dir,w)]);
    }

}

bool empty_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool empty_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}
