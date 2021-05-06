//
// Created by pc on 04.05.2021.
//

#include "cell.h"

#ifndef BLOCK_O_AUTOMATA_BARIER_CELL_H
#define BLOCK_O_AUTOMATA_BARRIER_CELL_H


class barrier_cell:public cell {
public:
    barrier_cell(bool movable);

    void show_in_console_unicode() override;

    barrier_cell &operator=(const barrier_cell &other)  = default;

    void action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) override;

    void move(std::vector<cell *> &plane, direction move_to, unsigned int h, unsigned int w,
              coord position_in_plane) override;

protected:
    std::string cell_name = "barrier";
};


#endif //BLOCK_O_AUTOMATA_BARRIER_CELL_H
