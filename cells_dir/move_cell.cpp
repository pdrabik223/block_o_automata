//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"

move_cell::move_cell(direction moveDirection) : cell(true, false),
                                                move_direction(moveDirection) {}

void move_cell::show_in_console_unicode() {
    if (move_direction == left) std::wcout << cc(yellow) << L"\x2B9C ";

   else if (move_direction == right) std::wcout << cc(yellow) << L"\x2B9E ";

  else  if (move_direction == up)std::wcout << cc(yellow) << L"\x2B9D ";

   else if (move_direction == down)std::wcout << cc(yellow) << L"\x2B9F ";


}
