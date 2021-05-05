//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_KILL_CELL_H
#define BLOCK_O_AUTOMATA_KILL_CELL_H


#include "cell.h"

class kill_cell: public cell {
public:
    kill_cell( unsigned int lives);

    kill_cell();

    void show_in_console_unicode() override;

protected:
    /// how many hits cells an take
    unsigned int lives;
};


#endif //BLOCK_O_AUTOMATA_KILL_CELL_H
