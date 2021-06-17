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

  MoveCell(Direction move_direction);

  MoveCell &operator=(const MoveCell &other) = default;

    icon GetUnicode() override;

    void Action(const std::vector<Cell *> &plane, unsigned w, Coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, Direction move_dir,
              Coord curr_pos,
              unsigned int width) override;

    bool operator==(const Type &rhs) const override;

    bool operator!=(const Type &rhs) const override;

    void SetMoveDirection(Direction move_direction);

    Direction GetMoveDirection() const;

    Type GetCellType() const override;

    void RotateRight()  noexcept override;

    void OutputFoFile(std::ostream &out) override;

static Type cell_type_;

MoveCell *Clone() override;

protected:
  Direction move_direction;


};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_MOVE_CELL_H_
