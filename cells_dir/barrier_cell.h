//
// Created by pc on 04.05.2021.
//

#include "cell.h"

#ifndef BLOCK_O_AUTOMATA_BARIER_CELL_H
#define BLOCK_O_AUTOMATA_BARRIER_CELL_H


class BarrierCell :public Cell {
public:
  BarrierCell();
  BarrierCell(bool movable);

    Type GetCellType() const override;

    icon GetUnicode() override;

    BarrierCell &operator=(const BarrierCell &other)  = default;

    void Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int width) override;

    bool operator==(const Type &rhs) const override;

    bool operator!=(const Type &rhs) const override;

    void RotateRight()  noexcept override{};

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    BarrierCell * Clone() override;

protected:

};


#endif //BLOCK_O_AUTOMATA_BARRIER_CELL_H
