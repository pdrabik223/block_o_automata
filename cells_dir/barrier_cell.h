//
// Created by pc on 04.05.2021.
//

#include "cell.h"

#ifndef BLOCK_O_AUTOMATA_BARIER_CELL_H
#define BLOCK_O_AUTOMATA_BARRIER_CELL_H


class barrier_cell:public cell {
public:
    barrier_cell();
    barrier_cell(bool movable);

    type getCellType() const override;

    icon get_unicode() override;

    barrier_cell &operator=(const barrier_cell &other)  = default;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    bool operator==(const type &rhs) const override;

    bool operator!=(const type &rhs) const override;

    void rotateRight()  noexcept override{};


    void output_fo_file(std::ostream &out) override;

protected:
    const type cell_type = Barrier;

};


#endif //BLOCK_O_AUTOMATA_BARRIER_CELL_H
