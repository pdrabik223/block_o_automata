//
// Created by pc on 12.05.2021.
//

#include <windows_console/edit.h>
#include <windows_console/pick.h>
#include <windows_console/play.h>

#include "board.h"

int main() {
  lc::PlayerAction player_choice = lc::PLAY_LEVEL;

  win_console::Pick main_menu;

  while (1 < 2) {
    {
      LevelInfo played_level;

      player_choice = main_menu.SelectLevel();
      played_level = main_menu.GetLevel();

      if (player_choice == lc::PLAY_LEVEL) {

        win_console::Play game(played_level);
        game.MainLoop();

      } else if (player_choice == lc::ENTER_EDITOR) {
        win_console::Edit editor;
        editor.MainLoop();
      }

      if (player_choice == lc::QUIT_GAME)
        break;
    }
  }

  return 0;
}
