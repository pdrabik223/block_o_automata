//
// Created by pc on 05.05.2021.
//

#include "board.h"

void board::iterate() {

    std::vector<cell *> level_copy;
    for (int i = 0; i < level.size(); ++i)
        level_copy.push_back(level[i]);

    for (int i = 0; i < level.size(); ++i) {

        level[i]->action(level.getLevel(), level.getWidth(),
                         {i / level.getWidth(), i % level.getWidth()},
                         level_copy);

    }
    for (int i = 0; i < level.size(); i++)
        level[i] = level_copy[i];

    counter++;
}

void board::lock_cells() {
    for (int i = 0; i < level.size(); i++) {
        if (*level[i] == Empty)
            level[i] = new empty_cell(true);

    }
}

bool board::goal_cells_left() {
    for (int i = 0; i < level.size(); i++) {
        if (*level[i] == Goal) return true;
    }
    return false;
}

board::board(level_info &played_level) {
level = played_level;
lock_cells();
counter = 0;
}

icon board::get_cell_icon(coord position) {
    return level[position]->get_unicode();
}

unsigned int board::get_counter() const {
    return counter;
}