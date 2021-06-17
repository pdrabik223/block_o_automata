//
// Created by studio25 on 26.05.2021.
//

#include "icon.h"

icon::icon() {
    image =  ' ';
    text_color = WHITE;
    background_color = BLACK;
}

icon::icon(wchar_t image, Color icon_color) : image(image), text_color(icon_color),background_color(BLACK) {}

icon::icon(wchar_t image, Color text_color, Color background_color) :
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
