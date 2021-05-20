//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_GOAL_CELL_H
#define BLOCK_O_AUTOMATA_GOAL_CELL_H

#include "cell.h"

class goal_cell : public cell {
public:
    goal_cell();

    goal_cell &operator=(const goal_cell &other) = default;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination);

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    icon get_unicode() override;

    type getCellType() const override;

    void rotateRight()  noexcept override{};

    bool operator==(const type &rhs) const override;

    bool operator!=(const type &rhs) const override;

    friend std::ostream &operator<<(std::ostream &out, const goal_cell &ref);


protected:
    const type cell_type = Goal;
};


#endif //BLOCK_O_AUTOMATA_GOAL_CELL_H
