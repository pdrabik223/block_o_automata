//
// Created by studio25 on 26.05.2021.
//

#include "icon.h"

icon::icon() {
    image =  ' ';
    text_color = white;
    background_color = black;
}

icon::icon(wchar_t image, color iconColor) : image(image), text_color(iconColor),background_color(black) {}

icon::icon(wchar_t image, color text_color, color background_color) :
        image(image),
        text_color(text_color),
        background_color(background_color) {}

bool icon::operator==(const icon &rhs) const {
    return image == rhs.image &&
           text_color == rhs.text_color &&
           background_color == rhs.background_color;
}

bool icon::operator!=(const icon &rhs) const {
    return !(rhs == *this);
}
