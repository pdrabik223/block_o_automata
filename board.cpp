//
// Created by pc on 05.05.2021.
//

#include "board.h"



board::board(unsigned int w, unsigned int h) : w(w), h(h), counter(0) {

   // level.reserve(w * h);

    for (int i = 0; i < w * h; i++) {

        if (i % w == 0 || i / w == 0 || i / w == (h - 1) || i % w == (w - 1)) level.push_back( new barrier_cell(false));
        else level.push_back(new empty_cell(true));
    }

    level[w*h/2+5] = new goal_cell();
    level[w*h/2+6] = new kill_cell();
    level[w*h/2+7] = new spawn_cell(false ,up);
    level[w*h/2-2] = new turn_cell(down);

}

void board::show_level_win_console() {
    for (int i = 0; i < h ; i++) {
        for(int j=0;j<w;j++) {
            level[i*w+j]->show_in_console_unicode();
        }
        std::wcout<<"\n";
    }
    std::wcout<<"\n\n";

}
