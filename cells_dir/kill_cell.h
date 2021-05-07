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

    kill_cell &operator=(const kill_cell &other) = default;

    void move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) override;

    void action(std::vector<cell *> &plane, unsigned w, coord curr_pos) override;

    bool operator==(const type rhs) const override;

    bool operator!=(const type &rhs) const override;

protected:
    /// how many hits cells an take
    unsigned int lives;

    type cell_type = t_kill;
};


#endif //BLOCK_O_AUTOMATA_KILL_CELL_H
