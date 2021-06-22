//
// Created by studio25 on 20.05.2021.
//

#include "edit.h"

void win_console::Edit::ControlledView() {

  unsigned window_height = GetHeight() + 2;
  unsigned window_width = (GetWidth() + 2) > (all_blocks_.size() * 2)
                              ? (GetWidth() + 2)
                              : (all_blocks_.size() * 2);

  console_handle_.Resize(window_height, window_width);
  /// Clear buffer before overwriting it
  console_handle_.Clear();

  /// display the level
  for (unsigned i = 0; i < GetHeight(); i++) {
    for (unsigned j = 0; j < GetWidth(); j++) {

      console_handle_.SetPixel({i, j}, GetCell(i, j).GetUnicode());
    }
  }

  /// display quit icon a.k.a. little red < in the right top corner
  console_handle_.SetPixel({0, GetWidth()}, {(wchar_t)11164, RED, BLACK});

  /// display run simulation icon a.k.a. little red > in the right top corner
  console_handle_.SetPixel({1, GetWidth()}, {(wchar_t)11166, YELLOW, BLACK});

  /// display Save icon a.k.a \/
  if (level_name_ == "noname")
    console_handle_.SetPixel({2, GetWidth()}, {(wchar_t)11167, GRAY, BLACK});
  else
    console_handle_.SetPixel({2, GetWidth()}, {(wchar_t)11167, BLUE, BLACK});

  /// display info icon a.k.a. little blue i on the right bottom
  console_handle_.SetPixel({GetHeight(), GetWidth()}, {'i', BLUE, BLACK});

  /// display width controls:
  console_handle_.SetPixel({GetHeight() - 2, GetWidth()}, {'-', YELLOW, BLACK});
  console_handle_.SetPixel({GetHeight() - 1, GetWidth()}, {'+', YELLOW, BLACK});

  /// display height controls:
  console_handle_.SetPixel({GetHeight(), GetWidth() - 2}, {'-', YELLOW, BLACK});
  console_handle_.SetPixel({GetHeight(), GetWidth() - 1}, {'+', YELLOW, BLACK});

  for (unsigned i = 0; i < all_blocks_.size() * 2; i += 2) {
    console_handle_.SetPixel({GetHeight() + 1, i}, {' ', WHITE, BLACK});
    console_handle_.SetPixel({GetHeight() + 1, i + 1},
                             all_blocks_[(i / 2)]->GetUnicode());
  }

  /// display cursor
  console_handle_.GetPixel(cursor_position_).background_color = LIGHT_AQUA;

  /// display cursor
  console_handle_.GetPixel({GetHeight() + 1, (current_block_ * 2) + 1})
      .background_color = LIGHT_AQUA;

  DisplayMessage();

  console_handle_.UpdateScreen();
}
/// todo complete run sim
///  we need better press to continue
///  but we need it everywhere
///  we need iteration counter
///  display blocks amounts
/// todo all around code strengthening

void win_console::Edit::RunSim() {
  Board game(*this);
  console_handle_.Resize(GetHeight() + 1, GetWidth() + 1);
  cursor_position_.x_ += 2;
  bool activate_quit = false;

  while (2 > 1) {

    /// Clear buffer before overwriting it
    console_handle_.Clear();

    for (unsigned i = 0; i < GetHeight(); i++) {
      for (unsigned j = 0; j < GetWidth(); j++) {
        console_handle_.SetPixel({i, j}, game.GetCellIcon({i, j}));
      }
    }
    /// display quit icon a.k.a. little red < in the right top corner
    console_handle_.SetPixel({0, GetWidth()},
                             {(wchar_t)11164, RED, LIGHT_AQUA});

    key_pressed input = null;

    input = console_handle_.AwaitKeyPress(std::chrono::milliseconds(250));

    switch (input) {
    case key_space:
    case key_enter:
      if (activate_quit) {
        return;
      }
    }

    current_message_ = le::EXIT;
    DisplayMessage();

    console_handle_.UpdateScreen();

    game.Iterate();

    activate_quit = true;
  }
}

void win_console::Edit::SetAdditionalInfo() {

  system("cls");
  std::wcout << Cc(BLUE, BLACK);
  std::wcout << "\nlevel name :";
  std::cin >> level_name_;

  std::wcout << "\nauthor :";
  std::cin >> author_;

  int temp_int;

  std::wcout << Cc(YELLOW, BLACK);
  std::wcout << "\nmax iterations  :";
  std::cin >> temp_int;

  if (temp_int >= 99)
    temp_int = 99;
  if (temp_int < 0)
    temp_int = 0;
  max_iteration_ = temp_int;

  std::wcout << "\nmax piece cost  :";
  std::cin >> temp_int;

  if (temp_int >= 99)
    temp_int = 99;
  if (temp_int < 0)
    temp_int = 0;
  max_piece_cost_ = temp_int;

  std::wcout << Cc(YELLOW, BLACK);

  system("cls");
  std::wcout << "changes saved";
  std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

unsigned char win_console::Edit::GetKey() {
  switch (console_handle_.AwaitKeyPress()) {
  case key_space:
    return 32;
  case key_enter:
    return 13;
  case key_delete:
    return 127;
  case key_0:
    return '0';
  case key_1:
    return '1';
  case key_2:
    return '2';
  case key_3:
    return '3';
  case key_4:
    return '4';
  case key_5:
    return '5';
  case key_6:
    return '6';
  case key_7:
    return '7';
  case key_8:
    return '8';
  case key_9:
    return '9';
  case key_a:
    return 'a';
  case key_w:
    return 'w';
  case key_s:
    return 's';
  case key_d:
    return 'd';
  case key_q:
    return 'q';
  case key_e:
    return 'e';
  case key_r:
    return 'r';
  case key_x:
    return 'x';
  default:
    assert(false);
    return '\0';
  }
}

void win_console::Edit::DisplayMessage() {
  switch (current_message_) {
  case le::EXIT:
    console_handle_.SetMessage(RED, BLACK, L"exit");
    break;

  case le::START_SIMULATION:
    console_handle_.SetMessage(YELLOW, BLACK, L"run simulation");
    break;
  case le::SAVE_CHANGES_TO_FILE:
    console_handle_.SetMessage(BLUE, BLACK, L"Save current changes");
    break;
  case le::ADDITIONAL_INFO_REQUEST:
    console_handle_.SetMessage(RED, BLACK, L"additional info is needed ");
    break;
  case le::INCREASE_WIDTH:
    console_handle_.SetMessage(YELLOW, BLACK,
                               L"increase width of the playing field");
    break;
  case le::INCREASE_HEIGHT:
    console_handle_.SetMessage(YELLOW, BLACK,
                               L"increase height of the playing field");
    break;
  case le::DECREASE_WIDTH:
    console_handle_.SetMessage(YELLOW, BLACK,
                               L"decrease width of the playing field");
    break;
  case le::DECREASE_HEIGHT:
    console_handle_.SetMessage(YELLOW, BLACK,
                               L"decrease height of the playing field");
    break;
  case le::ADDITIONAL_INFO:
    console_handle_.SetMessage(BLUE, BLACK, L"input additional info");
    break;
  case le::NONE:
    break;
  }
  current_message_ = le::NONE;
}
