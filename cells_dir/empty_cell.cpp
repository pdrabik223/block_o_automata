//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

empty_cell::empty_cell( bool locked) : cell(false, true), locked(locked) {}

void empty_cell::show_in_console_unicode() {
    if(locked)std::wcout<<"  ";
    else std::wcout<<cc(gray)<<L"\x2022 ";
}

void empty_cell::action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) {}
