//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_BOARD_H
#define BLOCK_O_AUTOMATA_BOARD_H

#include "level_dir/level_info.h"

#include <vector>
#include <iostream>
#include <string>



class board {
public:
    board(level_info &level);

    /// for now, later it will be moved to different class
    void show_level_win_console();

    /// \brief the heart of this game
    void iterate();

    ///\brief changes state of all empty cells to locked
    /// so player can't access them, also board looks way better that way
    void lock_cells();

    /// \return true if there is at least one goal_cell left on level
    bool goal_cells_left();

    /// \return true if there is at least one kill_cell left on level
    bool kill_cells_left();

    /// safely ( only on allowed squares ) places target cell
    ///
    /// \param position position in level that target will replace
    /// \param target will be in place after replacement
    /// \return true if placement succeeded<br> false if not
    bool put_piece(coord position, cell *target);

private:
    unsigned transform(unsigned int height, unsigned int width);

    /// frame counter
    /// may come handy later
    unsigned counter;
    /// cell array used to store current level state
     level_info level;

};


#endif //BLOCK_O_AUTOMATA_BOARD_H
