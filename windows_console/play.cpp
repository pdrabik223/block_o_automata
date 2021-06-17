//
// Created by studio25 on 20.05.2021.
//

#include "play.h"

void win_console::Play::ControlledView() {

  unsigned window_height = GetHeight() + 2;
  unsigned window_width = (GetWidth() + 1) > (all_blocks_.size() * 2)
                              ? (GetWidth() + 1)
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

  /// display win trophy
  if (level_beaten_)
    console_handle_.SetPixel({4, GetWidth()}, {(wchar_t)11201, PURPLE, BLACK});
  else
    console_handle_.SetPixel({4, GetWidth()}, {(wchar_t)11201, GRAY, BLACK});

  /// display blocks trophy
  if (max_piece_cost_beaten_)
    console_handle_.SetPixel({5, GetWidth()}, {(wchar_t)11202, YELLOW, BLACK});
  else
    console_handle_.SetPixel({5, GetWidth()}, {(wchar_t)11202, GRAY, BLACK});

  /// display iterations trophy
  if (max_iteration_beaten_)
    console_handle_.SetPixel({6, GetWidth()}, {(wchar_t)11042, RED, BLACK});
  else
    console_handle_.SetPixel({6, GetWidth()}, {(wchar_t)11042, GRAY, BLACK});

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

int win_console::Play::RunSim() {

  Board game(*this);
  cursor_position_.x_--;
  bool activate_quit = false;
  while (2 > 1) {

    game.Iterate();

    /// Clear buffer before overwriting it
    console_handle_.Clear();

    for (unsigned i = 0; i < GetHeight(); i++) {
      for (unsigned j = 0; j < GetWidth(); j++) {
        console_handle_.SetPixel({i, j}, game.GetCellIcon({i, j}));
      }
    }

    /// display quit icon a.k.a. little red < in the right top corner
    console_handle_.SetPixel({0, GetWidth()}, {(wchar_t)11164, RED, BLACK});

    /// display win trophy
    if (level_beaten_)
      console_handle_.SetPixel({4, GetWidth()},
                               {(wchar_t)11201, PURPLE, BLACK});
    else
      console_handle_.SetPixel({4, GetWidth()}, {(wchar_t)11201, GRAY, BLACK});

    /// display blocks trophy
    if (max_piece_cost_beaten_)
      console_handle_.SetPixel({5, GetWidth()},
                               {(wchar_t)11202, YELLOW, BLACK});
    else
      console_handle_.SetPixel({5, GetWidth()}, {(wchar_t)11202, GRAY, BLACK});

    /// display iterations trophy
    if (max_iteration_beaten_)
      console_handle_.SetPixel({6, GetWidth()}, {(wchar_t)11042, RED, BLACK});
    else
      console_handle_.SetPixel({6, GetWidth()}, {(wchar_t)11042, GRAY, BLACK});

    key_pressed input = null;

    input = console_handle_.AwaitKeyPress(std::chrono::milliseconds(200));

    switch (input) {
    case key_space:
    case key_enter:
      if (cursor_position_ == Coord(0, GetWidth()) && activate_quit)
        return 2;
    }

    /// display cursor
    console_handle_.GetPixel(cursor_position_).background_color = LIGHT_AQUA;

    DisplayMessage();

    console_handle_.UpdateScreen();

    if (!game.GoalCellsLeft()) {
      system("cls");

      std::wcout << Cc(YELLOW, BLACK) << "u are winner!";
      level_beaten_ = true;
      if (game.GetCounter() <= max_iteration_)
        max_iteration_beaten_ = true;

      int empty_block_counter_origin = 0;
      int empty_block_counter_copy = 0;
      for (auto i : level_)
        if (i->GetCellType() == EMPTY)
          if (!((EmptyCell *)i)->IsLocked())
            empty_block_counter_copy++;

      for (auto i : original_level_)
        if (i->GetCellType() == EMPTY)
          if (!((EmptyCell *)i)->IsLocked())
            empty_block_counter_origin++;

      if (empty_block_counter_origin - empty_block_counter_copy <=
          max_piece_cost_)
        ;
      max_piece_cost_beaten_ = true;

      std::swap(level_, original_level_);
      Save();
      std::swap(level_, original_level_);
      GetKey();
      return 1;
    }
    activate_quit = true;
  }
}

unsigned char win_console::Play::GetKey() {
  switch (console_handle_.AwaitKeyPress()) {

  case key_enter:
    return 13;
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
  case key_a:
    return 'a';
  case key_w:
    return 'w';
  case key_s:
    return 's';
  case key_d:
    return 'd';
  case key_r:
    return 'r';

  default:

    return '\0';
  }
}

void win_console::Play::DisplayMessage() {
  switch (current_message_) {
  case lp::EXIT:
    console_handle_.SetMessage(RED, BLACK, L"exit");
    break;

  case lp::START_SIMULATION:
    console_handle_.SetMessage(YELLOW, BLACK, L"run simulation");
    break;
  case lp::CANT_PLACE_BLOCK_HERE:
    console_handle_.SetMessage(RED, BLACK,
                               L"Cell can't be placed on this square");
    break;
  case lp::NO_MORE_BLOCKS_LEFT:

    console_handle_.SetMessage(RED, BLACK, L"no more blocks of this Type");
    break;

  case lp::LOSE:
    console_handle_.SetMessage(RED, BLACK, L"you lost");
    break;
  case lp::WIN:
    console_handle_.SetMessage(YELLOW, BLACK, L"congratulations you won!");
    break;
  case lp::WIN_TROFEUM:
    console_handle_.SetMessage(YELLOW, BLACK,
                               L"congratulations you won trofeum!");
    break;
    // todo display the range
  case lp::MINIMAL_COST_TROFEUM:

    if (max_piece_cost_beaten_)
      console_handle_.SetMessage(
          BLUE, BLACK, L"finishing level using minimal number of cells");
    else
      console_handle_.SetMessage(BLUE, BLACK,
                                 L"finish level using minimal number of cells");

    break;
  case lp::MINIMAL_ITERATIONS_TROFEUM:
    if (max_iteration_beaten_)
      console_handle_.SetMessage(
          BLUE, BLACK, L"finishing level in minimal number of iterations");
    else
      console_handle_.SetMessage(
          BLUE, BLACK, L"finish level in minimal number of iterations");
    break;
  case lp::NONE:

    break;
  }

  current_message_ = lp::NONE;
}
