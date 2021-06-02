//
// Created by studio25 on 26.05.2021.
//

#include <conio.h>
#include <string>
#include <thread>
#include "scml.h"


scml::scml() {
    text_color = white;
    background_color = black;
    w = 0;
    h = 0;
    message_text_color = white;
    message_background_color = black;

    message = {};
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
   // _setmode(_fileno(stdout), _O_U16TEXT);

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

    std::shared_future<int> future = std::async(std::launch::async, []() {
        //   std::this_thread::sleep_for(std::chrono::seconds(3));
        return getch();
    });
    std::future_status status;
    status = future.wait_for(await_time);
   // do {
        if (status == std::future_status::timeout || status == std::future_status::deferred)
        return null;
  //  } while (status != std::future_status::ready);

    switch (future.get()) {
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
    return null;
}

