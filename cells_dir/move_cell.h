//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_MOVE_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_MOVE_CELL_H_

#include "cell.h"

/// can move only in the Move direction
class MoveCell : public Cell {
public:
  MoveCell();

  MoveCell(direction move_direction);

  MoveCell &operator=(const MoveCell &other) = default;

    icon GetUnicode() override;

    void Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int width) override;

    bool operator==(const Type &rhs) const override;

    bool operator!=(const Type &rhs) const override;

    void SetMoveDirection(direction move_direction);

    direction GetMoveDirection() const;

    Type GetCellType() const override;

    void RotateRight()  noexcept override;

    void OutputFoFile(std::ostream &out) override;

static Type cell_type_;

MoveCell *Clone() override;

protected:
    direction move_direction;


};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_MOVE_CELL_H_
