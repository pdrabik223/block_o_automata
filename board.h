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

    /// \brief the heart of this game
    void iterate();

    ///\brief changes state of all empty cells to locked
    /// so player can't access them, also board looks way better that way
    void lock_cells();

    /// \return true if there is at least one goal_cell left on level
    bool goal_cells_left();

    /// used to move functions displaying the cells outside board
    /// \param position at witch wanted cell is stored
    /// \return information needed to proper display cell
    icon get_cell_icon(coord position);

    unsigned int get_counter() const;

private:
    /// frame counter
    /// may come handy later
    unsigned counter;
    /// cell array used to store current level state
    level_info level;

};


#endif //BLOCK_O_AUTOMATA_BOARD_H
