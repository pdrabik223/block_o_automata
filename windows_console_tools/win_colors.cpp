//
// Created by pc on 05.05.2021.
//

#include "win_colors.h"

cc::cc(color text, color background) : text(text), background(background) {
    HANDLE hc;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc, text+background*16);
}

cc::cc(color text) : text(text), background(black) {
    HANDLE hc;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc, text+background*16);
}

std::ostream &operator<<(std::ostream &out, const cc &ref) {
    return out;
}

std::wostream &operator<<(std::wostream &out, const cc &ref) {
    return out;
}
