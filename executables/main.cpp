//
// Created by pc on 04.05.2021.
//

/// the first approach

#include "board.h"
#include "windows_console_tools/win_colors.h"

/// the plan

/// todo make special class for displaying stuff
/// todo create whole game sequence:
#include <chrono>
#include <thread>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::seconds(x))

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
  /// allow using chart in console
  _setmode(_fileno(stdout), _O_U16TEXT);

  std::wcout << cc(gray) << "barrier_cell\t" << (wchar_t)(9635) << " \n";
  std::wcout << cc(gray) << "movable_barrier_cell\t" << (wchar_t)(9634)
             << " \n";
  std::wcout << cc(red) << "KillCell\t" << (wchar_t)10006 << " \n";

  std::wcout << cc(yellow) << "MoveCell\t" << (wchar_t)11166 << " \n\t\t"
             << (wchar_t)11164 << " \n\t\t" << (wchar_t)11165 << " \n\t\t"
             << (wchar_t)11167 << std::endl;

  std::wcout << cc(green) << "spawn_cell\t" << (wchar_t)11166 << " \n\t\t"
             << (wchar_t)11164 << " \n\t\t" << (wchar_t)11165 << " \n\t\t"
             << (wchar_t)11167 << std::endl;

  std::wcout << cc(blue) << "turn_cell\t" << (wchar_t)11166 << " \n\t\t"
             << (wchar_t)11164 << " \n\t\t" << (wchar_t)11165 << " \n\t\t"
             << (wchar_t)11167 << std::endl;

  wchar_t goal = 11044;
  std::wcout << cc(purple) << "GoalCell\t" << goal << L" \n";

  std::wcout << cc(yellow) << "trophy1\t" << (wchar_t)11201 << L" \n";

  std::wcout << cc(purple) << "trophy2\t" << (wchar_t)11202 << L" \n";

  std::wcout << cc(red) << "trophy3\t" << (wchar_t)11042 << L" \n";

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

  Board first(level);

  char k;
  int frame_counter = 0;

  while (2 > 1) {
    for (unsigned h = 0; h < level.GetHeight(); h++) {
      for (unsigned w = 0; w < level.GetWidth(); w++) {

        color text_color = first.GetCellIcon({h, w}).text_color;
        color background_color = black;
        first.GetCellIcon({h, w});
        std::wcout << cc(text_color, background_color)
                   << first.GetCellIcon({h, w}).image << " ";
      }
      std::wcout << "\n";
    }

    std::wcout << "\n\n";
    first.Iterate();
    std::wcout << cc(yellow, black) << "frame counter :" << cc(red)
               << frame_counter << std::endl;
    ++frame_counter;
    WAIT(2);
  }

  return 0;
}

#pragma clang diagnostic pop