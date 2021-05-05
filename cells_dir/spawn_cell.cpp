//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"

spawn_cell::spawn_cell(bool movable, unsigned int lives, direction spawnDirection) : cell(movable, true),
                                                                                     lives(lives),
                                                                                     spawn_direction(spawnDirection) {}

spawn_cell::spawn_cell(bool movable, direction spawnDirection) : cell(movable, true),
                                                                 lives(-1),
                                                                 spawn_direction(spawnDirection) {}

void spawn_cell::show_in_console_unicode() {
    if (spawn_direction == left) std::wcout << cc(green) << L"\x2B9C ";

    else if (spawn_direction == right) std::wcout << cc(green) << L"\x2B9E ";

    else  if (spawn_direction == up)std::wcout << cc(green) << L"\x2B9D ";

    else if (spawn_direction == down)std::wcout << cc(green) << L"\x2B9F ";
}
