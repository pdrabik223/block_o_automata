//
// Created by studio25 on 20.05.2021.
//

#include <windows_console/play.h>


level_info dummy_level();

int main() {
    level_info level = dummy_level();

    win_console::play game(level);
    game.main_loop();

    return 0;
}






level_info dummy_level() {

    level_info level{10, 10};
    for (int i = 0; i < level.size(); i++) {

        if (i % level.getWidth() == 0 ||
            i / level.getWidth() == 0 ||
            i / level.getWidth() == (level.getHeight() - 1) ||
            i % level.getWidth() == (level.getWidth() - 1))
            level[i] = new barrier_cell(false);

        else level[i] = new empty_cell(true);
    }

    level[{3, 6}] = new goal_cell();
    level[{3, 5}] = new kill_cell();


    level[{5, 8}] = new turn_cell(down);

    level[{0, 7}] = new barrier_cell(true);
    level[{1, 7}] = new spawn_cell(down);

    level[{1, 1}] = new turn_cell(right);

    level[{1, level.getWidth() - 4}] = new turn_cell(down);
    level[{level.getHeight() - 2, level.getWidth() - 2}] = new turn_cell(left);
    level[{level.getHeight() - 2, 1}] = new turn_cell(up);


    level[{2, 2}] = new kill_cell();
    level[{2, 3}] = new kill_cell();
    level[{2, 4}] = new kill_cell();

    level[{6, 2}] = new kill_cell();
    level[{6, 3}] = new kill_cell();
    level[{6, 4}] = new kill_cell();


    for (unsigned i = 2; i < 5; ++i) {
        level[{3, i}] = new empty_cell(false);
        level[{4, i}] = new empty_cell(false);
        level[{5, i}] = new empty_cell(false);
    }

    level[{5, 4}] = new move_cell(right);

    return level;
}