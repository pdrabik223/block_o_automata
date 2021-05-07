//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_MOVE_CELL_H
#define BLOCK_O_AUTOMATA_MOVE_CELL_H

#include "cell.h"

/// can move only in the move direction
class move_cell : public cell {
public:
    move_cell(direction moveDirection);

    void show_in_console_unicode() override;

    move_cell &operator=(const move_cell &other) = default;


    void action(std::vector<cell *> &plane, unsigned w, coord curr_pos) override;

    void move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) override;

    bool operator==(const type rhs) const override;

    bool operator!=(const type &rhs) const override;

protected:
    direction move_direction;

    type cell_type = t_move;

    bool has_been_moved = false;
};


#endif //BLOCK_O_AUTOMATA_MOVE_CELL_H
