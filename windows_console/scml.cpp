//
// Created by studio25 on 26.05.2021.
//

#include <conio.h>
#include <string>
#include <thread>
#include <array>
#include "scml.h"

#define HIGH_BIT  32768
#define LOW_BIT  32768

scml::scml() {
    text_color = white;
    background_color = black;
    w = 0;
    h = 0;
    message_text_color = white;
    message_background_color = black;

    message = {};
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);

}

scml::scml(unsigned int width, unsigned int height) : w(width), h(height) {
    text_color = white;
    background_color = black;
    /// it ain't the fastest
    for (int x = 0; x < h; x++) {
        std::vector<icon> temp;
        for (int y = 0; y < w; y++) {
            temp.emplace_back(' ', white, black);
        }
        buffer.push_back(temp);
    }

    message_text_color = white;
    message_background_color = black;

    message = {};

    /// here when I wrote    buffer.emplace_back("  ", white, black);
    /// the clion didn't shout at me
    /// witch is odd
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);
    system("cls");
}

scml::scml(const scml &other) {
    text_color = other.text_color;
    background_color = other.background_color;
    w = other.w;
    h = other.h;
    message_text_color = other.message_text_color;
    message_background_color = other.message_background_color;

    message = other.message;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);

    buffer = other.buffer;
}

scml &scml::operator=(const scml &other) {
    if (this == &other) return *this;
    text_color = other.text_color;
    background_color = other.background_color;
    w = other.w;
    h = other.h;

    message_text_color = other.message_text_color;
    message_background_color = other.message_background_color;

    message = other.message;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    _setmode(_fileno(stdout), _O_U16TEXT);

    buffer = other.buffer;
    return *this;

}


void scml::clear() {
    for (auto &i:buffer) {
        for (auto &j:i) {
            j.image = ' ';
            j.text_color = white;
            j.background_color = black;
        }
    }
    message = {};
}
/// so what I can do, is make check for every key
/// and check whether it's pressed at one specific time
/// than I can check if it's unpressed

key_pressed scml::await_key_press() {
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

            case 'q':
                return key_q;

            case 'e':
                return key_e;

            case 'r':
                return key_r;


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
    assert(position.x < h && position.y < w);
    buffer[position.x][position.y] = new_pixel;

}

void scml::update_screen() {

    COORD c;

    c.X = 0;
    c.Y = 0;

    SetConsoleCursorPosition(hc, c);

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {

            text_color = buffer[x][y].text_color;
            background_color = buffer[x][y].background_color;

            std::wcout << cc(text_color, background_color);
            /// don't forget that space brother
            std::wcout << buffer[x][y].image << ' ';


        }
        std::wcout << " \n";
    }
    std::wcout << L"                                                        \r";
    std::wcout << cc(message_text_color, message_background_color) << message;
    std::wcout << cc(white, black);
}

icon &scml::get_pixel(coord position) {
    assert(position.x < h && position.y < w);
    return buffer[position.x][position.y];
}

void scml::resize(unsigned int new_height, unsigned int new_width) {
    if (new_width < w) downsize_w(new_width);
    else if (new_width > w) upsize_w(new_width);

    if (new_height < h) downsize_h(new_height);
    else if (new_height > h) upsize_h(new_height);

}

void scml::downsize_w(unsigned int new_width) {
    int delta = w - new_width;
    assert(delta >= 0);

    for (auto &i:buffer)
        for (unsigned j = 0; j < delta; j++)
            i[w - 1 - j].image = ' ';

    update_screen();

    for (auto &i:buffer)
        i.resize(new_width);

    w = new_width;
}

void scml::upsize_w(unsigned int new_width) {
    int delta = new_width - w;
    assert(delta >= 0);

    for (auto &i:buffer)
        i.resize(new_width);
    w = new_width;
}

void scml::downsize_h(unsigned int new_height) {

    for (int i = new_height; i < h; i++)
        for (auto &j:buffer[i])
            j = {' ', white, black};
    update_screen();

    buffer.resize(new_height);
    h = new_height;

}

void scml::upsize_h(unsigned int new_height) {

    buffer.resize(new_height);
    for (auto &i:buffer)
        for (int j = 0; j < w; j++)
            i.emplace_back(' ', white, black);

    h = new_height;

}

void scml::set_message(color text_color, color background_color, std::wstring message) {

    this->message = message;
    message_text_color = text_color;
    message_background_color = background_color;
}


key_pressed scml::await_key_press(std::chrono::milliseconds await_time) {
    /// for button to be registered  it's need to be pressed and released
    /// and it must be the same button
    /// so we  need a way to store last button that was pressed
    key_pressed last_button_id = null;

    for (int i = 0; i < await_time.count() / 2; i++) {
        /// i dont even
        /// ught https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate

        if (GetKeyState(VK_LEFT) & HIGH_BIT)
            last_button_id = key_a;
        else if (last_button_id == key_a)
            return key_a;

        if (GetKeyState(VK_UP) & HIGH_BIT)
            last_button_id = key_w;
        else if (last_button_id == key_w)
            return key_w;

        if (GetKeyState(VK_DOWN) & HIGH_BIT)
            last_button_id = key_s;
        else if (last_button_id == key_s)
            return key_s;

        if (GetKeyState(VK_RIGHT) & HIGH_BIT)
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


