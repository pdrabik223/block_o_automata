//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_TURN_CELL_H
#define BLOCK_O_AUTOMATA_TURN_CELL_H

#include "cell.h"

class turn_cell : public cell{
public:
    turn_cell(unsigned int rotationsLeft, direction turnDirection);

    turn_cell(direction turnDirection);

    void show_in_console_unicode() override;

    turn_cell &operator=(const turn_cell &other) = default;

protected:
    /// how many rotations can cell preform
    unsigned rotations_left;
    /// the direction that incoming cell will leave with
    direction turn_direction;

};


#endif //BLOCK_O_AUTOMATA_TURN_CELL_H
