//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EMPTY_CELL_H
#define BLOCK_O_AUTOMATA_EMPTY_CELL_H
#include "cell.h"

class empty_cell: public cell{

public:
    empty_cell( bool locked);

    void show_in_console_unicode() override;

protected:
    /// can player put cells in place this one
    bool locked;
};


#endif //BLOCK_O_AUTOMATA_EMPTY_CELL_H
