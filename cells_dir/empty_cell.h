//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_EMPTY_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_EMPTY_CELL_H_
#include "cell.h"

class EmptyCell : public Cell {

public:
  EmptyCell();
  EmptyCell( bool locked);

    Type GetCellType() const override;

    EmptyCell &operator=(const EmptyCell &other)  = default;

    void Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int width) override;

    icon GetUnicode() override;

    bool IsLocked() const;

    void RotateRight()  noexcept override{};

    void SetLocked(bool locked);

    bool operator==(const Type & rhs) const override;

    bool operator!=(const Type &rhs) const override;

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    EmptyCell * Clone() override;

protected:
    /// can player put cells in place this one
    bool locked;
};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_EMPTY_CELL_H_
