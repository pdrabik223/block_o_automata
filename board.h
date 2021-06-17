//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA__BOARD_H_
#define BLOCK_O_AUTOMATA__BOARD_H_

#include "level_dir/level_info.h"

#include <iostream>
#include <string>
#include <vector>

class Board {
public:
  Board(LevelInfo &level);

  /// \brief the heart of this game
  void Iterate();

  ///\brief changes state of all empty cells to locked
  /// so player can't access them, also board looks way better that way
  void LockCells();

  /// \return true if there is at least one GoalCell left on level
  bool GoalCellsLeft();

  /// used to Move functions displaying the cells outside board
  /// \param position at witch wanted Cell is stored
  /// \return information needed to proper display Cell
  icon GetCellIcon(Coord position);

  unsigned int GetCounter() const;

private:
  /// frame counter
  /// may come handy later
  unsigned counter_;
  /// Cell array used to store current level state
  LevelInfo level_;
};

#endif // BLOCK_O_AUTOMATA__BOARD_H_
