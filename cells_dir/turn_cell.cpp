//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"
#include "move_cell.h"
#include "empty_cell.h"

turn_cell::turn_cell(unsigned int rotationsLeft, direction turnDirection) : cell(false, true),
                                                                            rotations_left(rotationsLeft),
                                                                            turn_direction(turnDirection) {}

turn_cell::turn_cell(direction turnDirection) : cell(false, true),
                                                rotations_left(-1),
                                                turn_direction(turnDirection) {}

void turn_cell::show_in_console_unicode() {
    if (turn_direction == left) std::wcout << cc(blue) << L"\x2B9C ";

    else if (turn_direction == right) std::wcout << cc(blue) << L"\x2B9E ";

    else if (turn_direction == up)std::wcout << cc(blue) << L"\x2B9D ";

    else if (turn_direction == down)std::wcout << cc(blue) << L"\x2B9F ";
}

void turn_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
    return;
}

void turn_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                     unsigned int w) {

    plane[curr_pos.go(turn_direction, w)]->move(plane, destination, turn_direction, curr_pos.go(turn_direction), w);


    if (*plane[curr_pos.go(turn_direction, w)] == t_empty) {

            // me                                      the one in front
            std::swap(destination[curr_pos.reverse(move_dir, w)], destination[curr_pos.go(turn_direction, w)]);

        if(*destination[curr_pos.go(turn_direction, w)] == t_move)  destination[curr_pos.go(turn_direction, w)] = new move_cell(turn_direction);

    }


}

bool turn_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool turn_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

