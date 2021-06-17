//
// Created by pc on 05.05.2021.
//

#include "board.h"

void Board::Iterate() {

  std::vector<Cell *> level_copy;
  for (int i = 0; i < level_.Size(); ++i)
    level_copy.push_back(level_[i]->Clone());

  /// First we activate all spawn cells
  for (int i = 0; i < level_.Size(); ++i) {
    if (*level_[i] == SPAWN) {
      level_[i]->Action(level_.GetLevel(), level_.GetWidth(),
                        {i / level_.GetWidth(), i % level_.GetWidth()},
                        level_copy);
      for (int i = 0; i < level_.Size(); i++)
        level_[i] = level_copy[i]->Clone();
    }
  }

  /// next all Move cells
  /// this approach won't eliminate all of my problems
  /// but at least will deal with one

  for (int i = 0; i < level_.Size(); ++i) {
    if (*level_[i] == MOVE) {
      level_[i]->Action(level_.GetLevel(), level_.GetWidth(),
                        {i / level_.GetWidth(), i % level_.GetWidth()},
                        level_copy);

      for (int i = 0; i < level_.Size(); i++)
        level_[i] = level_copy[i]->Clone();
    }
  }

  for (int i = 0; i < level_.Size(); i++)
    level_[i] = level_copy[i];

  counter_++;
}

void Board::LockCells() {
  for (int i = 0; i < level_.Size(); i++) {
    if (*level_[i] == EMPTY)
      level_[i] = new EmptyCell(true);
  }
}

bool Board::GoalCellsLeft() {
  for (int i = 0; i < level_.Size(); i++) {
    if (*level_[i] == GOAL)
      return true;
  }
  return false;
}

Board::Board(LevelInfo &played_level) {
  level_ = played_level;
  LockCells();
  counter_ = 0;
}

icon Board::GetCellIcon(Coord position) {
  return level_[position]->GetUnicode();
}

unsigned int Board::GetCounter() const { return counter_; }