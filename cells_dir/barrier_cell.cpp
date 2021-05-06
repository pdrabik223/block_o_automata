//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

barrier_cell::barrier_cell(bool movable) : cell(movable, false) {}

void barrier_cell::show_in_console_unicode() {
    if(movable) std::wcout<<cc(gray)<<L"\x25A2 ";
    else std::wcout<<cc(gray)<<L"\x25A3 ";

}

void barrier_cell::action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) {
   return;
}

void barrier_cell::move(std::vector<cell *> &plane, direction move_to, unsigned int h, unsigned int w,
                        coord position_in_plane) {
    switch (move_to) {
        case left:
            plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)];
            break;
        case right:
            plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)];
            break;
        case up:
            plane[toUint({position_in_plane.x + 1, position_in_plane.y}, w)];
            break;
        case down:
            plane[toUint({position_in_plane.x - 1, position_in_plane.y}, w)];
            break;
    }

}
