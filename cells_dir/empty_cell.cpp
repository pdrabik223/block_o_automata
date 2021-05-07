//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

empty_cell::empty_cell( bool locked) : cell(false, true), locked(locked) {}

void empty_cell::show_in_console_unicode() {
    if(locked)std::wcout<<"  ";
    else std::wcout<<cc(gray)<<L"\x2022 ";
}

void empty_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {}

void empty_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                      unsigned int w) {

    if(*plane[curr_pos.go(move_dir,w)] == t_empty){
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(w)] ,destination[curr_pos.go(move_dir,w)]);
    }

}

bool empty_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool empty_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}
