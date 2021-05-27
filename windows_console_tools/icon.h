//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_ICON_H
#define BLOCK_O_AUTOMATA_ICON_H


#include "win_colors.h"

struct icon {
    icon();

    icon(const std::wstring &image, color iconColor);

    icon(const std::wstring &image, color text_color, color background_color);

    std::wstring image;
    color text_color;
    color background_color;

    bool operator==(const icon &rhs) const;

    bool operator!=(const icon &rhs) const;
};


#endif //BLOCK_O_AUTOMATA_ICON_H
