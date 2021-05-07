//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"
#include "empty_cell.h"

move_cell::move_cell(direction moveDirection) : cell(true, true),
                                                move_direction(moveDirection) {}

void move_cell::show_in_console_unicode() {
    if (move_direction == left) std::wcout << cc(yellow) << L"\x2B9C ";

    else if (move_direction == right) std::wcout << cc(yellow) << L"\x2B9E ";

    else if (move_direction == up)std::wcout << cc(yellow) << L"\x2B9D ";

    else if (move_direction == down)std::wcout << cc(yellow) << L"\x2B9F ";


}

void move_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {

    if (!has_been_moved) {
        plane[curr_pos.go(move_direction, w)]->move(plane, move_direction, w,
                                                    curr_pos.go(move_direction));

        if (*plane[curr_pos.go(move_direction, w)] == t_empty) {
            // me                                      the one in front
            std::swap(plane[curr_pos.toUint(w)], plane[curr_pos.go(move_direction, w)]);
        }
    }

    if (*plane[curr_pos.go(move_direction, w)] == t_empty) {
        // me                                      the one in front
        cell temp = *plane[curr_pos.go(move_direction, w)];
        *plane[curr_pos.go(move_direction, w)] = *plane[curr_pos.toUint(w)];
        *plane[curr_pos.toUint(w)] = temp;
        std::wcout << "here!";
    }


    has_been_moved = false;

}

void move_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {
    has_been_moved = true;
    plane[curr_pos.go(move_dir, w)]->move(plane, move_dir, w, curr_pos.go(move_dir));


    if (*plane[curr_pos.go(move_dir, w)] == t_empty) {
        // me                                      the one in front

        cell temp = *plane[curr_pos.go(move_dir, w)];
        *plane[curr_pos.go(move_dir, w)] = *plane[curr_pos.toUint(w)];
        *plane[curr_pos.toUint(w)] = temp;

    }

}

bool move_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool move_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}
