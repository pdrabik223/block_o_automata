//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_GOAL_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_GOAL_CELL_H_

#include "cell.h"

class GoalCell : public Cell {
public:
  GoalCell();

  GoalCell &operator=(const GoalCell &other) = default;

    void Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int width) override;

    icon GetUnicode() override;

    Type GetCellType() const override;

    void RotateRight()  noexcept override{};

    bool operator==(const Type &rhs) const override;

    bool operator!=(const Type &rhs) const override;

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    GoalCell *Clone() override;

protected:
};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_GOAL_CELL_H_
