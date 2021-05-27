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


    class scml {

    public:
        scml(unsigned int w, unsigned int h);

        key_pressed await_key_press();

        std::string await_string();

        int await_int();

        void update_screen();

        void set_pixel(coord position, icon new_pixel);

        icon& get_pixel(coord position);

        void clear();


    private:
        unsigned w;
        unsigned h;
        color text_color;
        color background_color;
        std::vector<icon> buffer;
        HANDLE hc;

    };

#endif //BLOCK_O_AUTOMATA_SCML_H
