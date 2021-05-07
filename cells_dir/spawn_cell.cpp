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

    else if (spawn_direction == up)std::wcout << cc(green) << L"\x2B9D ";

    else if (spawn_direction == down)std::wcout << cc(green) << L"\x2B9F ";
}

void spawn_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {
    plane[curr_pos.go(spawn_direction, w)]->
    move(plane, spawn_direction, w,curr_pos.go(spawn_direction));

    if (*plane[curr_pos.go(spawn_direction, w)] == t_empty) {
        // me                                      the one in front
        if (*plane[curr_pos.reverse(spawn_direction, w)] == t_empty)
            plane[curr_pos.go(spawn_direction, w)] = new cell(*plane[curr_pos.reverse(spawn_direction, w)]);
    }
}

void spawn_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {
    plane[curr_pos.go(move_dir, w)]->move(plane, move_dir, w, curr_pos.go(move_dir));

    if (*plane[curr_pos.go(move_dir, w)] == t_empty) {
        // me                                      the one in front
        std::swap(plane[curr_pos.toUint(w)], plane[curr_pos.go(move_dir, w)]);
    }
}

bool spawn_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool spawn_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}
