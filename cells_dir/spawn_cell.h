//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_SPAWN_CELL_H
#define BLOCK_O_AUTOMATA_SPAWN_CELL_H


#include "cell.h"

class spawn_cell: public cell {
public:
    spawn_cell(bool movable,  unsigned int lives, direction spawnDirection);

    spawn_cell(bool movable,  direction spawnDirection);

    void show_in_console_unicode() override;

    void action(std::vector<cell *> &plane, unsigned w, coord curr_pos) override;

    void move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) override;

    bool operator==(const type rhs) const override;

    bool operator!=(const type &rhs) const override;

protected:
    /// how many more cells can be spawned
    unsigned lives;
    /// the place where cell be spawned
    direction spawn_direction;

    type cell_type = t_spawn;
};


#endif //BLOCK_O_AUTOMATA_SPAWN_CELL_H
