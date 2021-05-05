//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELL_H
#define BLOCK_O_AUTOMATA_CELL_H

#include <iostream>

#include "../windows_console_tools/win_colors.h"

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

class cell {


public:
    cell();

    cell(bool movable, bool hollow);

    bool isMovable() const;

    void setMovable(bool movable);

    void setHollow(bool hollow);

    bool isHollow() const;

    virtual void show_in_console_unicode(){}

protected:
    /// can be moved/rotated by other cells
    bool movable;
    /// can other cells enter this one
    bool hollow;

};


#endif //BLOCK_O_AUTOMATA_CELL_H
