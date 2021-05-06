//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_BOARD_H
#define BLOCK_O_AUTOMATA_BOARD_H


#include "cells_dir/barrier_cell.h"
#include "cells_dir/empty_cell.h"
#include "cells_dir/goal_cell.h"
#include "cells_dir/kill_cell.h"
#include "cells_dir/spawn_cell.h"
#include "cells_dir/move_cell.h"
#include "cells_dir/turn_cell.h"

#include <vector>
#include <iostream>
#include <string>

class board {
public:
    board(unsigned int w, unsigned int h);

    void load_level(std::string file_path);
    void save_level(std::string file_path);
    /// for now, later it will be moved to different class
    void show_level_win_console();

    /// \return pointer to a chosen cell in level
    /// \param width of a chosen cell
    /// \param wight  of a chosen cell
    cell & get_cell(unsigned height, unsigned width);


    /// \return pointer to a chosen cell in level
    /// \param position coordinates of wanted cell
    cell & get_cell(coord position);

    /// \brief the heart of this game
    void iterate();


private:
    unsigned transform(unsigned int height, unsigned int width);


    /// both width and height include frames around level
    /// width in cells
    unsigned w;
    /// height in cells
    unsigned h;
    /// frame counter
    /// may come handy later
    unsigned counter;
    /// cell array used to store current level state
    std::vector<cell*> level;

};


#endif //BLOCK_O_AUTOMATA_BOARD_H
