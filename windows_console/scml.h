//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_SCML_H
#define BLOCK_O_AUTOMATA_SCML_H

#include "windows_console_tools/win_colors.h"
#include "windows_console_tools/coord.h"
#include "windows_console_tools/icon.h"

#include <vector>

enum key_pressed {

    key_space,
    key_enter,
    key_delete,
    key_0,
    key_1,
    key_2,
    key_3,
    key_4,
    key_5,
    key_6,
    key_7,
    key_8,
    key_9,
    key_a,
    key_w,
    key_s,
    key_d,
    key_q,
    key_e,
    key_r,
    key_i
};

/// simple console media layer
/// step between our app and device console
/// contains buffer of wchar_t values that will be displayed on screen
/// every character will be followed by space

//todo better use press detection
// idk how much time i want to spend at it
// i guess we'll see
// for now it runs of getch()
// I'll try with getline

class scml {

public:

    scml();
    scml(const scml& other);
    scml(unsigned int width, unsigned int height);
    scml& operator=(const scml& other);

    key_pressed await_key_press();

    std::string await_string();

    int await_int();

    void update_screen();

    void set_pixel(coord position, icon new_pixel);

    icon &get_pixel(coord position);

    void resize(unsigned int new_width, unsigned int new_height);

    void clear();

    ~scml() {
        std::wcout << cc(white, black);
        system("cls");
    }

private:
    void downsize_w(unsigned new_width);
    void upsize_w(unsigned new_width);

    void downsize_h(unsigned new_height);
    void upsize_h(unsigned new_height);


    unsigned h;
    unsigned w;
    color text_color;
    color background_color;
    std::vector<std::vector<icon>> buffer;
    HANDLE hc;

};

#endif //BLOCK_O_AUTOMATA_SCML_H
