//
// Created by studio25 on 26.05.2021.
//

#include <conio.h>
#include <string>
#include "scml.h"


scml::scml(unsigned int w, unsigned int h) : w(w), h(h) {
    text_color = white;
    background_color = black;
    for (int i = 0; i < w * h; i++)
        buffer.emplace_back(L" ", white, black);
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);
    system("cls");
}

void scml::clear() {
    for (auto &i:buffer) {
        i.image = L"  ";
        i.text_color = text_color;
        i.background_color = background_color;
    }
}

key_pressed scml::await_key_press() {
    char key;
    while (2 > 1) {
        key = getch();
        switch (key) {
            case 32:
                return key_space;

            case 13:
                return key_enter;

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

            case 'q':
                return key_q;

            case 'e':
                return key_e;

            case 'r':
                return key_r;

            case 'i':
                return key_i;

            default:
                break;
        }
    }
}

std::string scml::await_string() {
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

int scml::await_int() {
    int temp;
    std::cin >> temp;
    return temp;
}

void scml::set_pixel(coord position, icon new_pixel) {
    buffer[position.toUint(w)] = new_pixel;
}

void scml::update_screen() {

    COORD c;

    c.X = 0;
    c.Y = 0;

    SetConsoleCursorPosition(hc, c);

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {


            text_color = buffer[x * w + y].text_color;
            background_color = buffer[x * w + y].background_color;

            std::wcout << cc(text_color, background_color);
            std::wcout << buffer[x * w + y].image;


        }
        std::wcout << "\n";
    }
}

icon &scml::get_pixel(coord position) {
    return buffer[position.toUint(w)];
}
