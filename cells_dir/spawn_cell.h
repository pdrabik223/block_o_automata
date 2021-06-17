//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELLS_DIR_SPAWN_CELL_H_
#define BLOCK_O_AUTOMATA_CELLS_DIR_SPAWN_CELL_H_

#include "cell.h"

class SpawnCell : public Cell {
public:
  SpawnCell();

  SpawnCell(Direction spawn_direction);

  SpawnCell &operator=(const SpawnCell &other) = default;

    icon GetUnicode() override;

    void Action(const std::vector<Cell *> &plane, unsigned w, Coord curr_pos, std::vector<Cell *> &destination) override;

    void Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, Direction move_dir,
              Coord curr_pos,
              unsigned int width) override;

    bool operator==(const Type &rhs) const override;

    bool operator!=(const Type &rhs) const override;

    Direction GetSpawnDirection() const;

    void SetSpawnDirection(Direction spawn_direction);

    Type GetCellType() const override;

    void RotateRight() noexcept override;

    void OutputFoFile(std::ostream &out) override;

    static Type cell_type_;

    SpawnCell *Clone() override;

protected:

    /// the place where Cell be spawned
  Direction spawn_direction_;

};


#endif // BLOCK_O_AUTOMATA_CELLS_DIR_SPAWN_CELL_H_
