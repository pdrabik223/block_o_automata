//
// Created by pc on 05.05.2021.
//

#include "board.h"


void board::show_level_win_console() {
    for (int i = 0; i < level.getHeight(); i++) {
        for (int j = 0; j < level.getWidth(); j++) {
            level[i * level.getWidth() + j]->show_in_console_unicode();
        }
        std::wcout << "\n";
    }
    std::wcout << "\n\n";

}


unsigned board::transform(unsigned int height, unsigned int width) {
    return height * level.getWidth() + width;
}


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


}

void board::lock_cells() {
    for (int i = 0; i < level.size(); i++) {
        if (*level[i] == t_empty)
            level[i] = new empty_cell(true);

    }
}


bool board::goal_cells_left() {
    for (int i = 0; i < level.size(); i++) {
        if (*level[i] == t_goal) return true;
    }
    return false;
}

bool board::kill_cells_left() {
    for (int i = 0; i < level.size(); i++) {
        if (*level[i] == t_kill) return true;
    }
    return false;
}

board::board(level_info &played_level) {
level = played_level;
}
