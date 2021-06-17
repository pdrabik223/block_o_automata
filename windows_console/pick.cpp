//
// Created by studio25 on 20.05.2021.
//

#include "pick.h"

void win_console::Pick::DisplayUi() {

  Levelvec levels;
  LoadLevels(loaded_levels_, levels, directory_path_);

  system("cls");

  int j;
  j = 0;
  for (; j < levels.size(); j++) {

    if (cursor_position_ == j) {
      std::wcout << Cc(RED, GRAY) << " " << j << ".   ";
      std::wcout << Cc(YELLOW, GRAY) << levels[j].GetInfo();

      if (levels[j].level_beaten_)
        std::wcout << Cc(PURPLE, GRAY) << L" " << (wchar_t)11201 << L"  ";
      else
        std::wcout << Cc(YELLOW, GRAY) << L"    ";

      if (levels[j].max_piece_cost_beaten_)
        std::wcout << Cc(YELLOW, GRAY) << L" " << (wchar_t)11202 << L"  ";
      else
        std::wcout << Cc(YELLOW, GRAY) << L"    ";

      if (levels[j].max_iteration_beaten_)
        std::wcout << Cc(RED, GRAY) << L" " << (wchar_t)11042 << L"  ";
      else
        std::wcout << Cc(YELLOW, GRAY) << L"    ";

      std::wcout << Cc(WHITE, BLACK);
    } else {
      std::wcout << Cc(RED, BLACK) << j << ".   ";
      std::wcout << Cc(YELLOW, BLACK) << levels[j].GetInfo();

      if (levels[j].level_beaten_)
        std::wcout << Cc(PURPLE, BLACK) << L" " << (wchar_t)11201 << L"  ";
      else
        std::wcout << Cc(YELLOW, BLACK) << L"    ";

      if (levels[j].max_piece_cost_beaten_)
        std::wcout << Cc(YELLOW, BLACK) << L" " << (wchar_t)11202 << L"  ";
      else
        std::wcout << Cc(YELLOW, BLACK) << L"    ";

      if (levels[j].max_iteration_beaten_)
        std::wcout << Cc(RED, BLACK) << L" " << (wchar_t)11042 << L"  ";
      else
        std::wcout << Cc(YELLOW, BLACK) << L"    ";
      std::wcout << Cc(WHITE, BLACK);
    }
    std::wcout << L"\n";
  }

  if (cursor_position_ == levels.size()) {

    std::wcout << Cc(RED, GRAY) << " " << j << ".   ";
    std::wcout << Cc(YELLOW, GRAY) << L"create level...\n";
    std::wcout << Cc(WHITE, BLACK);

  } else {

    std::wcout << Cc(RED, BLACK) << j << ".   ";
    std::wcout << Cc(YELLOW, BLACK) << L"create level...\n";
    std::wcout << Cc(WHITE, BLACK);
  }

  if (cursor_position_ == levels.size() + 1) {

    std::wcout << Cc(RED, GRAY) << " " << j + 1 << ".   ";
    std::wcout << Cc(YELLOW, GRAY) << L"exit game";
    std::wcout << Cc(WHITE, BLACK);

  } else {

    std::wcout << Cc(RED, BLACK) << j + 1 << ".   ";
    std::wcout << Cc(YELLOW, BLACK) << L"exit game";
    std::wcout << Cc(WHITE, BLACK);
  }
}

unsigned char win_console::Pick::GetKey() { return getch(); }
