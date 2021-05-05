//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

barrier_cell::barrier_cell(bool movable) : cell(movable, false) {}

void barrier_cell::show_in_console_unicode() {
    if(movable) std::wcout<<cc(gray)<<L"\x25A2 ";
    else std::wcout<<cc(gray)<<L"\x25A3 ";

}
