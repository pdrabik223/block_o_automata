//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_GOAL_CELL_H
#define BLOCK_O_AUTOMATA_GOAL_CELL_H

#include "cell.h"

class goal_cell : public cell {
public:
    goal_cell();

    void show_in_console_unicode() override;

    goal_cell &operator=(const goal_cell &other) = default;

    void action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane);


protected:
    std::string cell_name = "goal";
};


#endif //BLOCK_O_AUTOMATA_GOAL_CELL_H
