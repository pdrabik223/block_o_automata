//
// Created by pc on 13.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PLAY_H_
#define BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PLAY_H_

#include "level_info.h"
#include <conio.h>

namespace lp {
enum PlayerAction { NOTHING, QUIT_GAME, RUN_SIMULATION };

enum Message {
  NONE,
  EXIT,
  START_SIMULATION,
  CANT_PLACE_BLOCK_HERE,
  NO_MORE_BLOCKS_LEFT,
  LOSE,
  WIN,
  WIN_TROFEUM,
  MINIMAL_COST_TROFEUM,
  MINIMAL_ITERATIONS_TROFEUM

};

class LevelPlay : public LevelInfo {
public:
  LevelPlay() : LevelInfo() {}

  LevelPlay(const LevelInfo &other) : LevelInfo(other) {}

  PlayerAction MainLoop();

  PlayerAction AnalyzeMovement(char key);

  virtual void ControlledView(){};

  virtual int RunSim() {
    assert(false);
    return -1;
  };

  virtual unsigned char GetKey() {
    assert(false);
    return -1;
  };

protected:
  unsigned current_block_ = 0;

  Message current_message_ = NONE;

  coord cursor_position_ = {0, 0};

  std::array<Cell *, 5> all_blocks_ = {new BarrierCell(), new BarrierCell(true),
                                       new MoveCell(up), new TurnCell(up),
                                       new SpawnCell(up)};
  std::vector<Cell *> original_level_;
};
} // namespace lp

#endif // BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PLAY_H_
