//
// Created by studio25 on 26.05.2021.
//

#include "scml.h"
#include <array>
#include <conio.h>
#include <string>
#include <thread>

#define HIGH_BIT 32768
#define LOW_BIT 32768

Scml::Scml() {
  text_color_ = white;
  background_color_ = black;
  w = 0;
  h_ = 0;
  message_text_color_ = white;
  message_background_color_ = black;

  message_ = {};
  hc_ = GetStdHandle(STD_OUTPUT_HANDLE);
  _setmode(_fileno(stdout), _O_U16TEXT);
}

Scml::Scml(unsigned int width, unsigned int height) : w(width), h_(height) {
  text_color_ = white;
  background_color_ = black;
  /// it ain't the fastest
  for (int x = 0; x < h_; x++) {
    std::vector<icon> temp;
    for (int y = 0; y < w; y++) {
      temp.emplace_back(' ', white, black);
    }
    buffer_.push_back(temp);
  }

  message_text_color_ = white;
  message_background_color_ = black;

  message_ = {};

  /// here when I wrote    buffer.emplace_back("  ", white, black);
  /// the clion didn't shout at me
  /// witch is odd
  hc_ = GetStdHandle(STD_OUTPUT_HANDLE);
  _setmode(_fileno(stdout), _O_U16TEXT);
  system("cls");
}

Scml::Scml(const Scml &other) {
  text_color_ = other.text_color_;
  background_color_ = other.background_color_;
  w = other.w;
  h_ = other.h_;
  message_text_color_ = other.message_text_color_;
  message_background_color_ = other.message_background_color_;

  message_ = other.message_;
  hc_ = GetStdHandle(STD_OUTPUT_HANDLE);
  _setmode(_fileno(stdout), _O_U16TEXT);

  buffer_ = other.buffer_;
}

Scml &Scml::operator=(const Scml &other) {
  if (this == &other)
    return *this;
  text_color_ = other.text_color_;
  background_color_ = other.background_color_;
  w = other.w;
  h_ = other.h_;

  message_text_color_ = other.message_text_color_;
  message_background_color_ = other.message_background_color_;

  message_ = other.message_;
  hc_ = GetStdHandle(STD_OUTPUT_HANDLE);
  _setmode(_fileno(stdout), _O_U16TEXT);

  buffer_ = other.buffer_;
  return *this;
}

void Scml::Clear() {
  for (auto &i : buffer_) {
    for (auto &j : i) {
      j.image = ' ';
      j.text_color = white;
      j.background_color = black;
    }
  }
  message_ = {};
}
/// so what I can do, is make check for every key
/// and check whether it's pressed at one specific time
/// than I can check if it's unpressed

key_pressed Scml::AwaitKeyPress() {
  char key;
  while (2 > 1) {
    key = getch();
    switch (key) {
    case 32:
      return key_space;

    case 13:
      return key_enter;

    case 127:
      return key_delete;

    case '0':
      return key_0;

    case '1':
      return key_1;

    case '2':
      return key_2;

    case '3':
      return key_3;

    case '4':
      return key_4;

    case '5':
      return key_5;

    case '6':
      return key_6;

    case '7':
      return key_7;

    case '8':
      return key_8;

    case '9':
      return key_9;

    case 'a':
      return key_a;

    case 'w':
      return key_w;

    case 's':
      return key_s;

    case 'd':
      return key_d;

    case 'r':
      return key_r;

    case 'x':
      return key_x;

    default:
      break;
    }
  }
}

void Scml::SetPixel(coord position, icon new_pixel) {
  assert(position.x < h_ && position.y < w);
  buffer_[position.x][position.y] = new_pixel;
}

void Scml::UpdateScreen() {

  COORD c;

  c.X = 0;
  c.Y = 0;

  SetConsoleCursorPosition(hc_, c);

  for (int x = 0; x < h_; x++) {
    for (int y = 0; y < w; y++) {

      text_color_ = buffer_[x][y].text_color;
      background_color_ = buffer_[x][y].background_color;

      std::wcout << cc(text_color_, background_color_);
      /// don't forget that space brother
      std::wcout << buffer_[x][y].image << ' ';
    }
    std::wcout << " \n";
  }

  std::wcout
      << cc(white, black)
      << L"                                                               \r";
  std::wcout << cc(message_text_color_, message_background_color_) << message_;
  std::wcout << cc(white, black);
}

icon &Scml::GetPixel(coord position) {
  assert(position.x < h_ && position.y < w);
  return buffer_[position.x][position.y];
}

void Scml::Resize(unsigned int new_height, unsigned int new_width) {
  if (new_height < w)
    DownsizeW(new_height);
  else if (new_height > w)
    UpsizeW(new_height);

  if (new_width < h_)
    DownsizeH(new_width);
  else if (new_width > h_)
    UpsizeH(new_width);
}

void Scml::DownsizeW(unsigned int new_width) {
  int delta = w - new_width;
  assert(delta >= 0);
  message_ = {};
  for (auto &i : buffer_)
    for (unsigned j = 0; j < delta; j++)
      i[w - 1 - j].image = ' ';

  UpdateScreen();

  for (auto &i : buffer_)
    i.resize(new_width);

  w = new_width;
}

void Scml::UpsizeW(unsigned int new_width) {
  int delta = new_width - w;
  assert(delta >= 0);
  message_ = {};
  for (auto &i : buffer_)
    i.resize(new_width);
  w = new_width;
}

void Scml::DownsizeH(unsigned int new_height) {
  message_ = {};
  for (int i = new_height; i < h_; i++)
    for (auto &j : buffer_[i])
      j = {' ', white, black};
  UpdateScreen();

  buffer_.resize(new_height);
  h_ = new_height;
}

void Scml::UpsizeH(unsigned int new_height) {
  message_ = {};
  UpdateScreen();
  buffer_.resize(new_height);
  for (auto &i : buffer_)
    for (int j = 0; j < w; j++)
      i.emplace_back(' ', white, black);

  h_ = new_height;
}

void Scml::SetMessage(color text_color, color background_color,
                      std::wstring message) {

  this->message_ = message;
  message_text_color_ = text_color;
  message_background_color_ = background_color;
}

key_pressed Scml::AwaitKeyPress(std::chrono::milliseconds await_time) {
  /// for button to be registered  it's need to be pressed and released
  /// and it must be the same button
  /// so we  need a way to store last button that was pressed
  key_pressed last_button_id = null;

  for (int i = 0; i < await_time.count() / 2; i++) {
    /// i dont even
    /// ught
    /// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate

    if (GetKeyState(97) & HIGH_BIT)
      last_button_id = key_a;
    else if (last_button_id == key_a)
      return key_a;

    if (GetKeyState(119) & HIGH_BIT)
      last_button_id = key_w;
    else if (last_button_id == key_w)
      return key_w;

    if (GetKeyState(115) & HIGH_BIT)
      last_button_id = key_s;
    else if (last_button_id == key_s)
      return key_s;

    if (GetKeyState(100) & HIGH_BIT)
      last_button_id = key_d;
    else if (last_button_id == key_d)
      return key_d;

    if (GetKeyState(VK_SPACE) & HIGH_BIT)
      last_button_id = key_space;
    else if (last_button_id == key_space)
      return key_space;

    if (GetKeyState(VK_RETURN) & HIGH_BIT)
      last_button_id = key_enter;
    else if (last_button_id == key_enter)
      return key_enter;

    if (GetKeyState(VK_DELETE) & HIGH_BIT)
      last_button_id = key_delete;
    else if (last_button_id == key_delete)
      return key_delete;

    if (GetKeyState('0') & HIGH_BIT)
      last_button_id = key_0;
    else if (last_button_id == key_0)
      return key_0;

    if (GetKeyState('1') & HIGH_BIT)
      last_button_id = key_1;
    else if (last_button_id == key_1)
      return key_1;

    if (GetKeyState('2') & HIGH_BIT)
      last_button_id = key_2;
    else if (last_button_id == key_2)
      return key_2;

    if (GetKeyState('3') & HIGH_BIT)
      last_button_id = key_3;
    else if (last_button_id == key_3)
      return key_3;

    if (GetKeyState('4') & HIGH_BIT)
      last_button_id = key_4;
    else if (last_button_id == key_4)
      return key_4;

    if (GetKeyState('5') & HIGH_BIT)
      last_button_id = key_5;
    else if (last_button_id == key_5)
      return key_5;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  return null;
}
