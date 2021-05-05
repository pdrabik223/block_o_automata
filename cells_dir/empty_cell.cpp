//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

empty_cell::empty_cell( bool locked) : cell(false, true), locked(locked) {}

void empty_cell::show_in_console_unicode() {
    if(locked)std::wcout<<"  ";
    else std::wcout<<cc(gray)<<". ";
}
