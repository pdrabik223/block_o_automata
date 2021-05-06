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

void move_cell::action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) {


        switch (move_direction) {
            case left:
                plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)]->move(plane, left, h, w,
                                                                                       position_in_plane);
                break;
            case right:
                plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)]->move(plane, right, h, w,
                                                                                       position_in_plane);
                break;
            case up:
                plane[toUint({position_in_plane.x - 1, position_in_plane.y}, w)]->move(plane, up, h, w,
                                                                                       position_in_plane);
                break;
            case down:
                plane[toUint({position_in_plane.x + 1, position_in_plane.y}, w)]->move(plane, down, h, w,
                                                                                       position_in_plane);
                break;
        }

}
