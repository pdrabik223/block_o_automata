//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_ICON_H
#define BLOCK_O_AUTOMATA_ICON_H


#include "win_colors.h"

struct icon {
    icon();

    icon(wchar_t image, color iconColor);

    icon(wchar_t image, color text_color, color background_color);

    wchar_t image;
    color text_color;
    color background_color;

    bool operator==(const icon &rhs) const;

    bool operator!=(const icon &rhs) const;
};


#endif //BLOCK_O_AUTOMATA_ICON_H
