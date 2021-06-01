//
// Created by studio25 on 20.05.2021.
//


#include "play.h"


void win_console::play::controlled_view() {

    unsigned window_height = getHeight() + 2;
    unsigned window_width = (getWidth() + 1) > (all_blocks.size() * 2) ? (getWidth() + 1) : (all_blocks.size() * 2);


    console_handle.resize(window_height, window_width);

    /// clear buffer before overwriting it
    console_handle.clear();

    /// display the level
    for (unsigned i = 0; i < getHeight(); i++) {
        for (unsigned j = 0; j < getWidth(); j++) {

            console_handle.set_pixel({i, j}, get_cell(i, j).get_unicode());

        }
    }
    /// display quit icon a.k.a. little red < in the right top corner
    console_handle.set_pixel({0, getWidth()}, {(wchar_t) 11164, red, black});

    /// display run simulation icon a.k.a. little red > in the right top corner
    console_handle.set_pixel({1, getWidth()}, {(wchar_t) 11166, yellow, black});


    for (unsigned i = 0; i < all_blocks.size() * 2; i += 2) {
        console_handle.set_pixel({getHeight() + 1, i}, {' ', white, black});
        console_handle.set_pixel({getHeight() + 1, i + 1}, all_blocks[(i / 2)]->get_unicode());
    }

    ///display cursor
    console_handle.get_pixel(cursor_position).background_color = light_aqua;

    ///display cursor
    console_handle.get_pixel({getHeight() + 1, (current_block * 2) + 1}).background_color = light_aqua;

    display_message();

    console_handle.update_screen();

}

int win_console::play::run_sim() {

    board game(*this);
    while (2 > 1) {

        game.iterate();

        /// clear buffer before overwriting it
        console_handle.clear();

        for (unsigned i = 0; i < getHeight(); i++) {
            for (unsigned j = 0; j < getWidth(); j++) {
                console_handle.set_pixel({i, j}, game.get_cell_icon({i, j}));
            }
        }

        /// display quit icon a.k.a. little red < in the right top corner
        console_handle.set_pixel({0, getWidth()}, {(wchar_t) 11164, red, light_aqua});

        console_handle.update_screen();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (!game.goal_cells_left()) {
            system("cls");

            std::wcout << cc(yellow, black) << "u are winner!";

            get_key();
            return 1;
        }
    }
}

unsigned char win_console::play::get_key() {
    switch (console_handle.await_key_press()) {
        case key_space:
            return 32;
        case key_enter:
            return 13;
        case key_0:
            return '0';
        case key_1:
            return '1';
        case key_2:
            return '2';
        case key_3:
            return '3';
        case key_4:
            return '4';
        case key_5:
            return '5';
        case key_6:
            return '6';
        case key_7:
            return '7';
        case key_8:
            return '8';
        case key_9:
            return '9';
        case key_a:
            return 'a';
        case key_w:
            return 'w';
        case key_s:
            return 's';
        case key_d:
            return 'd';
        case key_q:
            return 'q';
        case key_e:
            return 'e';
        case key_r:
            return 'r';
        case key_i:
            return 'i';
        default:
            assert(false);
            return '\0';
    }
}

void win_console::play::display_message() {
    switch (current_message) {
        case lp::exit:
            console_handle.set_message(red, black, L"exit");
            break;

        case lp::start_simulation:
            console_handle.set_message(yellow, black, L"run simulation");
            break;
        case lp::cant_place_block_here:
            console_handle.set_message(red, black, L"cell can't be placed on this square");
            break;
        case lp::no_more_blocks_left:

            console_handle.set_message(red, black, L"no more blocks of this type");
            break;
        case lp::none:

            break;
    }
    current_message = lp::none;
}
