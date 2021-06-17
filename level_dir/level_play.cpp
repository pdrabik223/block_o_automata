//
// Created by pc on 13.05.2021.
//

#include "level_play.h"
#include <thread>

using namespace lp;

PlayerAction LevelPlay::MainLoop() {

  /// lock the  original level state
  original_level_ = level_;

  char key_pressed = 0;
  PlayerAction operation;

  while (2 > 1) {

    ControlledView();

    key_pressed = GetKey();

    operation = AnalyzeMovement(key_pressed);
    if (operation == QUIT_GAME)
      return QUIT_GAME;

    if (operation == RUN_SIMULATION)
      RunSim();
  }
}

PlayerAction LevelPlay::AnalyzeMovement(char key) {
  switch (key) {
  case 'a':
    cursor_position_.y--;
    break;
  case 'w':
    cursor_position_.x--;
    break;
  case 's':
    cursor_position_.x++;
    break;
  case 'd':
    cursor_position_.y++;
    break;
  case 13:

    // set pawn in place
    if (cursor_position_.x < GetHeight() && cursor_position_.y < GetWidth()) {
      /// if the Cell was originally empty
      if (*original_level_[cursor_position_.toUint(GetWidth())] == EMPTY) {
        /// and was assignable
        if (!((EmptyCell *)original_level_[cursor_position_.toUint(GetWidth())])
                 ->IsLocked()) {

          CopyCell(cursor_position_, all_blocks_[current_block_]);

        } else
          current_message_ = CANT_PLACE_BLOCK_HERE;
      } else
        current_message_ = CANT_PLACE_BLOCK_HERE;
    }

    /// if cursor is on "red < icon"
    if (cursor_position_ == coord(0, GetWidth())) {

      return QUIT_GAME;
    }

    /// if cursor is on "yellow >icon"
    if (cursor_position_ == coord(1, GetWidth())) {
      return RUN_SIMULATION;
    }

    /// if cursor is on "win trophy"
    if (cursor_position_ == coord(4, GetWidth())) {
      current_message_ = NONE;
    }
    /// if cursor is on "blocks trophy"
    if (cursor_position_ == coord(5, GetWidth())) {
      current_message_ = MINIMAL_COST_TROFEUM;
    }
    /// if cursor is on "iterations trophy"
    if (cursor_position_ == coord(6, GetWidth())) {
      current_message_ = MINIMAL_ITERATIONS_TROFEUM;
    }

    break;
  case 'r':
    operator[](cursor_position_)->RotateRight();
    break;
  case '1':
    current_block_ = 0;
    break;
  case '2':
    current_block_ = 1;
    break;
  case '3':
    current_block_ = 2;
    break;
  case '4':
    current_block_ = 3;
    break;
  case '5':
    current_block_ = 4;
    break;
  case 'x':
    CopyCell(cursor_position_,
             original_level_[cursor_position_.toUint(GetWidth())]);
    break;
  default:
    return NOTHING;
  }
  if (cursor_position_.y > GetWidth())
    cursor_position_.y = GetWidth();
  if (cursor_position_.x >= GetHeight())
    cursor_position_.x = GetHeight() - 1;

  if (cursor_position_.y < 0)
    cursor_position_.y = 0;
  if (cursor_position_.x < 0)
    cursor_position_.x = 0;

  /// if cursor is on "red < icon"
  if (cursor_position_ == coord(0, GetWidth())) {
    current_message_ = EXIT;
  }

  /// if cursor is on "yellow >icon"
  else if (cursor_position_ == coord(1, GetWidth())) {
    current_message_ = START_SIMULATION;
  }

  return NOTHING;
}
