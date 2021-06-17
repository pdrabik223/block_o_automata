//
// Created by studio25 on 20.05.2021.
//

#include <windows_console/play.h>

LevelInfo dummy_level();

int main() {
  LevelInfo level = dummy_level();

  win_console::Play game(level);
  game.MainLoop();

  return 0;
}

LevelInfo dummy_level() {

  LevelInfo level{10, 10};

  for (int i = 0; i < level.Size(); i++) {

    if (i % level.GetWidth() == 0 || i / level.GetWidth() == 0 ||
        i / level.GetWidth() == (level.GetHeight() - 1) ||
        i % level.GetWidth() == (level.GetWidth() - 1))
      level[i] = new BarrierCell(false);

    else
      level[i] = new EmptyCell(true);
  }

  level[{3, 6}] = new GoalCell();
  level[{3, 5}] = new KillCell();

  level[{5, 8}] = new TurnCell(down);

  level[{0, 7}] = new BarrierCell(true);
  level[{1, 7}] = new SpawnCell(down);

  level[{1, 1}] = new TurnCell(right);

  level[{1, level.GetWidth() - 4}] = new TurnCell(down);
  level[{level.GetHeight() - 2, level.GetWidth() - 2}] = new TurnCell(left);
  level[{level.GetHeight() - 2, 1}] = new TurnCell(up);

  level[{2, 2}] = new KillCell();
  level[{2, 3}] = new KillCell();
  level[{2, 4}] = new KillCell();

  level[{6, 2}] = new KillCell();
  level[{6, 3}] = new KillCell();
  level[{6, 4}] = new KillCell();

  for (unsigned i = 2; i < 5; ++i) {
    level[{3, i}] = new EmptyCell(false);
    level[{4, i}] = new EmptyCell(false);
    level[{5, i}] = new EmptyCell(false);
  }

  level[{5, 4}] = new MoveCell(right);

  return level;
}