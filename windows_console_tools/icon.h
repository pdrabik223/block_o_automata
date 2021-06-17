//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_ICON_H_
#define BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_ICON_H_

#include "win_colors.h"

struct icon {
  icon();

  icon(wchar_t image, Color icon_color);

  icon(wchar_t image, Color text_color, Color background_color);

  wchar_t image;
  Color text_color;
  Color background_color;

  bool operator==(const icon &rhs) const;

  bool operator!=(const icon &rhs) const;
};

#endif // BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_ICON_H_
