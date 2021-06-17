//
// Created by pc on 13.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_EDIT_H_
#define BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_EDIT_H_

#include "../board.h"
#include "level_info.h"
#include <conio.h>
#include <iostream>
#include <thread>

namespace le {
enum PlayerAction {
  NOTHING,
  QUIT_EDIT,
  RUN_SIMULATION
};

enum Message {
  NONE,
  EXIT,
  START_SIMULATION,
  SAVE_CHANGES_TO_FILE,
  ADDITIONAL_INFO_REQUEST,
  INCREASE_WIDTH,
  INCREASE_HEIGHT,
  DECREASE_WIDTH,
  DECREASE_HEIGHT,
  ADDITIONAL_INFO
};

class LevelEdit : public LevelInfo {
public:
  LevelEdit() : LevelInfo(10, 10) {}

  void MainLoop();

  PlayerAction AnalyzeMovement(char key);

  virtual void ControlledView() { assert(false); };

  virtual void RunSim() { assert(false); };

  virtual void SetAdditionalInfo() { assert(false); };

  virtual unsigned char GetKey() {
    assert(false);
    return -1;
  };

protected:
  void DisplayMessage();

  unsigned current_block_ = 0;

  Message current_message_ = NONE;

  Coord cursor_position_ = {0, 0};

  std::array<Cell *, 8> all_blocks_ = {new BarrierCell(),     //
                                       new BarrierCell(true), //
                                       new MoveCell(UP),      //
                                       new TurnCell(UP),      //
                                       new SpawnCell(UP),     //
                                       new KillCell(),        new GoalCell(),
                                       new EmptyCell(false)};
};
} // namespace le
#endif // BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_EDIT_H_
