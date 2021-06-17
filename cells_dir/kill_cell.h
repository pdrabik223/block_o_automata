//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_KILL_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_KILL_CELL_H_

#include "cell.h"

class KillCell : public Cell {
public:
  KillCell();

  KillCell &operator=(const KillCell &other) = default;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination,
            Direction move_dir, Coord curr_pos,
              unsigned int width) override;

    void Action(const std::vector<Cell *> &plane, unsigned w, Coord curr_pos,
                std::vector<Cell *> &destination) override;

    bool operator==(const Type &rhs) const override;

    icon GetUnicode() override;

    Type GetCellType() const override;

    bool operator!=(const Type &rhs) const override;

    void RotateRight() noexcept override {};

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    KillCell *Clone() override;

protected:

};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_KILL_CELL_H_
