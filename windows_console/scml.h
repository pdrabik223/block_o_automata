//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_SCML_H
#define BLOCK_O_AUTOMATA_SCML_H

#include "windows_console_tools/coord.h"
#include "windows_console_tools/icon.h"
#include "windows_console_tools/win_colors.h"
#include <chrono>
#include <future>
#include <thread>
#include <vector>

enum key_pressed {
  null = 0,
  key_enter,
  key_space,
  key_delete,
  key_0,
  key_1,
  key_2,
  key_3,
  key_4,
  key_5,
  key_6,
  key_7,
  key_8,
  key_9,
  key_a,
  key_w,
  key_s,
  key_d,
  key_q,
  key_e,
  key_r,
  key_x

};

/// simple console media layer
/// step between our app and device console
/// contains buffer of wchar_t values that will be displayed on screen
/// every character will be followed by space

// todo better use press detection
//  idk how much time i want to spend at it
//  i guess we'll see
//  for now it runs of getch()
//  I'll try with getline

class Scml {

public:
  Scml();

  Scml(const Scml &other);

  Scml(unsigned int width, unsigned int height);

  Scml &operator=(const Scml &other);

  key_pressed AwaitKeyPress();

  key_pressed AwaitKeyPress(std::chrono::milliseconds await_time);

  void SetMessage(Color text_color, Color background_color,
                  std::wstring message);

  void UpdateScreen();

  void SetPixel(Coord position, icon new_pixel);

  icon &GetPixel(Coord position);

  void Resize(unsigned int new_width, unsigned int new_height);

  void Clear();

  ~Scml() {
    std::wcout << Cc(WHITE, BLACK);
    system("cls");
  }

private:
  void DownsizeW(unsigned new_width);

  void UpsizeW(unsigned new_width);

  void DownsizeH(unsigned new_height);

  void UpsizeH(unsigned new_height);

  unsigned h_;
  unsigned w;
  Color text_color_;
  Color background_color_;
  std::vector<std::vector<icon>> buffer_;
  Color message_text_color_;
  Color message_background_color_;

  std::wstring message_;
  HANDLE hc_;
};

#endif // BLOCK_O_AUTOMATA_SCML_H
