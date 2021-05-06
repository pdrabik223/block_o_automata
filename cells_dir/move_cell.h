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

    move_cell &operator=(const move_cell &other)  = default;


    void action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) override;

protected:
direction move_direction;
    std::string cell_name = "move";
};


#endif //BLOCK_O_AUTOMATA_MOVE_CELL_H
