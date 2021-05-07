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

    void action(std::vector<cell *> &plane, unsigned w, coord curr_pos);

    void move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) override;

    bool operator==(const type rhs) const override;

    bool operator!=(const type &rhs) const override;

protected:
    type cell_type = t_goal;
};


#endif //BLOCK_O_AUTOMATA_GOAL_CELL_H
