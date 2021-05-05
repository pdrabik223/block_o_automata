//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"

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

