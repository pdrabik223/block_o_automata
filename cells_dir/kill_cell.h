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

    void move(std::vector<cell *> &plane, direction move_to, unsigned int h, unsigned int w,
              coord position_in_plane) override;

    void action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) override;

protected:
    /// how many hits cells an take
    unsigned int lives;

    std::string cell_name = "kill";
};


#endif //BLOCK_O_AUTOMATA_KILL_CELL_H
