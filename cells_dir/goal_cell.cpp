//
// Created by pc on 05.05.2021.
//

#include "goal_cell.h"
#include "empty_cell.h"

goal_cell::goal_cell() : cell(false, true) {}

void goal_cell::show_in_console_unicode() {
    std::wcout<<cc(purple)<<L"\x2B24 ";
}

void goal_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {
}

void goal_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {

    if(plane[curr_pos.reverse(move_dir,w)]->isKillable()){
        plane[curr_pos.reverse(move_dir,w)] = new empty_cell(false);
        plane[curr_pos.toUint(w)] = new empty_cell(false);
        return;
    }else {

        plane[curr_pos.go(move_dir, w)]->move(plane, move_dir, w, curr_pos.go(move_dir));

        if (*plane[curr_pos.go(move_dir, w)] == t_empty) {
            // me                                      the one in front
            std::swap(plane[curr_pos.toUint(w)], plane[curr_pos.go(move_dir, w)]);
        }
    }
}

bool goal_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool goal_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}
