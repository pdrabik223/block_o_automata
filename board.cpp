//
// Created by pc on 05.05.2021.
//

#include "board.h"


board::board(unsigned int w, unsigned int h) : w(w), h(h), counter(0) {

    // level.reserve(w * h);

    for (int i = 0; i < w * h; i++) {

        if (i % w == 0 || i / w == 0 || i / w == (h - 1) || i % w == (w - 1)) level.push_back(new barrier_cell(false));
        else level.push_back(new empty_cell(true));
    }

    level[transform(3, 6)] = new goal_cell();
    level[transform(3, 5)] = new kill_cell();


    level[transform(5, 8)] = new turn_cell(down);

    level[transform(0, 7)] = new barrier_cell(true);
    level[transform(1, 7)] = new spawn_cell(false, down);

    level[transform(1, 1)] = new turn_cell(right);

    level[transform(1, w - 4)] = new turn_cell(down);
    level[transform(h - 2, w - 2)] = new turn_cell(left);
    level[transform(h - 2, 1)] = new turn_cell(up);


    level[transform(2, 2)] = new kill_cell();
    level[transform(2, 3)] = new kill_cell();
    level[transform(2, 4)] = new kill_cell();

    level[transform(6, 2)] = new kill_cell();
    level[transform(6, 3)] = new kill_cell();
    level[transform(6, 4)] = new kill_cell();
    for (int i = 2; i < 5; ++i) {
        level[transform(3, i)] = new empty_cell(false);
        level[transform(4, i)] = new empty_cell(false);
        level[transform(5, i)] = new empty_cell(false);
    }

    level[transform(5, 4)] = new move_cell(right);
}

void board::show_level_win_console() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            level[i * w + j]->show_in_console_unicode();
        }
        std::wcout << "\n";
    }
    std::wcout << "\n\n";

}

cell &board::get_cell(unsigned int height, unsigned int width) {
    return *level[height * w + width];
}

unsigned board::transform(unsigned int height, unsigned int width) {
    return height * w + width;
}


void board::iterate() {

    std::vector<cell*> level_copy(w*h);

    for(int i=0;i<level.size();++i){


    }


}
