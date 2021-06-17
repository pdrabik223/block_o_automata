//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_TURN_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_TURN_CELL_H_

#include "cell.h"

class TurnCell : public Cell {
public:
  TurnCell();

  TurnCell(Direction turn_direction);

  TurnCell &operator=(const TurnCell &other) = default;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination,
            Direction move_dir, Coord curr_pos,
              unsigned int width) override;

    icon GetUnicode() override;

    void Action(const std::vector<Cell *> &plane, unsigned w, Coord curr_pos, std::vector<Cell *> &destination) override;

    bool operator==(const Type & rhs) const override;

    bool operator!=(const Type &rhs) const override;

    Type GetCellType() const override;

    Direction GetTurnDirection() const;

    void RotateRight() noexcept override;

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    TurnCell *Clone() override;

protected:

    /// the direction that incoming Cell will leave with
  Direction turn_direction;

};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_TURN_CELL_H_
