//
// Created by pc on 08.05.2021.
//
#include <windows_console/pick.h>

int main() {
  LevelInfo level;
  win_console::Pick cos;

  lc::PlayerAction command;
  command = cos.SelectLevel();
  level = cos.GetLevel();

  _setmode(_fileno(stdout), _O_U16TEXT);
  if (command == lc::PLAY_LEVEL)
    std::wcout << "\nchosen_level:\n" << level.GetInfo();
  if (command == lc::ENTER_EDITOR)
    std::wcout << "\nenter editor";

  getch();

  return 0;
}
