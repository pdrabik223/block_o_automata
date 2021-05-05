//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_MOVE_CELL_H
#define BLOCK_O_AUTOMATA_MOVE_CELL_H

#include "cell.h"

/// can move only in the move direction
class move_cell: public cell{
public:
    move_cell(direction moveDirection);

    void show_in_console_unicode() override;

protected:
direction move_direction;
};


#endif //BLOCK_O_AUTOMATA_MOVE_CELL_H
