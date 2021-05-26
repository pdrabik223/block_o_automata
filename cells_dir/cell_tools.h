//
// Created by pc on 07.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_COORD_H
#define BLOCK_O_AUTOMATA_COORD_H

#include <cassert>
#include "../windows_console_tools/win_colors.h"

/// type of the cell, used to identify cell by it's role
enum type {

    Barrier,
    Move,
    Kill,
    Spawn,
    Turn,
    Goal,
    Cell,
    Empty

};

/// used by few of the cells
/// the plane is always orientated the same way
/// so up is north on plane
/// there can be made some transformation
enum direction {
    left,
    right,
    up,
    down
};




#endif //BLOCK_O_AUTOMATA_COORD_H
