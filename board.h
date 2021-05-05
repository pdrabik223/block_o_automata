//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_BOARD_H
#define BLOCK_O_AUTOMATA_BOARD_H


#include "cells_dir/cell.h"
#include <vector>
#include <iostream>
#include <string>

class board {
public:
    board(unsigned int w, unsigned int h);


    void load_level(std::string level_path);
    void save_level(std::string level_path);
    /// for now, later it will be moved to different class
    void show_level_win_console();


private:
    /// width in cells
    unsigned w;
    /// height in cells
    unsigned h;
    std::vector<cell> level;
};


#endif //BLOCK_O_AUTOMATA_BOARD_H
