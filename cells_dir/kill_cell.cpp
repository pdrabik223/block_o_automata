//
// Created by pc on 04.05.2021.
//

#include "kill_cell.h"

kill_cell::kill_cell( unsigned int lives) : cell(false, true), lives(lives) {}

kill_cell::kill_cell() : cell(false, true), lives(-1)  {}

void kill_cell::show_in_console_unicode() {
    std::wcout<<cc(red)<<L"\x2716 ";
}