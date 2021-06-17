//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELL_H
#define BLOCK_O_AUTOMATA_CELL_H

#include <cassert>
#include <iostream>
#include <vector>

#include "../windows_console_tools/win_colors.h"

#include "../windows_console_tools/coord.h"
#include "../windows_console_tools/icon.h"

// todo smart pointers to minimize mem leaks

/// Type of the Cell, used to identify Cell by it's role
enum Type {

  CELL = 1,
  BARRIER = 2,
  MOVE = 3,
  KILL = 4,
  SPAWN = 5,
  TURN = 6,
  GOAL = 7,
  EMPTY = 8

};

class Cell {
public:
  Cell();

  Cell(bool movable, bool killable);

  bool IsMovable() const;

  void SetMovable(bool movable);

  void SetKillable(bool killable);

  bool IsKillable() const;

  virtual Cell &operator=(const Cell &other) = default;

  virtual void RotateRight() noexcept { assert(false); };

  virtual icon GetUnicode() {
    assert(false);
    return icon();
  };

  virtual void Move(const std::vector<Cell *> &plane,
                    std::vector<Cell *> &destination, Direction move_dir,
                    Coord curr_pos, unsigned int width) {
    assert(false);
  };

  virtual void Action(const std::vector<Cell *> &plane, unsigned w,
                      Coord curr_pos, std::vector<Cell *> &destination) {
    assert(false);
  };

  virtual bool operator==(const Type &rhs) const;

  virtual bool operator!=(const Type &rhs) const;

  virtual Type GetCellType() const;

  virtual void OutputFoFile(std::ostream &out) { assert(false); };

  virtual Cell *Clone() { return this; };

  static Type cell_type_;

protected:
  /// can be moved/rotated by other cells
  bool movable_;
  /// can this Cell be killed
  bool killable_;
};

#endif // BLOCK_O_AUTOMATA_CELL_H
