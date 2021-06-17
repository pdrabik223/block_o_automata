//
// Created by pc on 05.05.2021.
//

#include "win_colors.h"

Cc::Cc(Color text, Color background) : text_(text), background_(background) {
  HANDLE hc;
  hc = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hc, text + background * 16);
}

Cc::Cc(Color text) : text_(text), background_(BLACK) {
  HANDLE hc;
  hc = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hc, text + background_ * 16);
}

std::ostream &operator<<(std::ostream &out, const Cc &ref) { return out; }

std::wostream &operator<<(std::wostream &out, const Cc &ref) { return out; }
