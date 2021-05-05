//
// Created by pc on 05.05.2021.
//

#include "goal_cell.h"

goal_cell::goal_cell() : cell(false, true) {}

void goal_cell::show_in_console_unicode() {
    std::wcout<<cc(purple)<<L"\x2B24 ";
}
