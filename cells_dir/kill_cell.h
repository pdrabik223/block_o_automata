//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_KILL_CELL_H
#define BLOCK_O_AUTOMATA_KILL_CELL_H


#include "cell.h"

class kill_cell: public cell {
public:

    kill_cell();

    kill_cell &operator=(const kill_cell &other) = default;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    bool operator==(const type &rhs) const override;

    icon get_unicode() override;

    type getCellType() const override;

    bool operator!=(const type &rhs) const override;

    friend std::ostream &operator<<(std::ostream &out, const kill_cell &ref);


    void rotateRight() noexcept override {};

protected:

  const   type cell_type = Kill;
};


#endif //BLOCK_O_AUTOMATA_KILL_CELL_H
