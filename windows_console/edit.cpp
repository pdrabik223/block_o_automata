//
// Created by studio25 on 20.05.2021.
//

#include "edit.h"

void win_console::edit::controlled_view() {

    for (unsigned i = 0; i < getHeight(); i++) {
        for (unsigned j = 0; j < getWidth(); j++) {

            console_handle.set_pixel({i, j}, get_cell(i, j).get_unicode());

        }
    }
    /// display width controls:
    console_handle.set_pixel({getHeight() - 2, getWidth()}, {'-', yellow, black});
    console_handle.set_pixel({getHeight() - 1, getWidth()}, {'+', yellow, black});



    /// display height controls:
    for (unsigned i = 0; i < getWidth() - 2; i++)
        console_handle.set_pixel({getHeight(), i}, {' ', white, black});


    console_handle.set_pixel({getHeight(), getWidth() - 1}, {'-', yellow, black});
    console_handle.set_pixel({getHeight(), getWidth()}, {'+', yellow, black});


    ///display cursor
    console_handle.get_pixel(cursor_position).background_color = light_aqua;


  /// display blocks
    for (unsigned i = 0; i < all_blocks.size()*2; i+=2) {
        console_handle.get_pixel({getHeight() + 1, i}).image = ' ';
        console_handle.set_pixel({getHeight() + 1, i + 1}, all_blocks[i]->get_unicode());
    }

    /// display cursor on screen
    console_handle.get_pixel({getHeight() + 1, current_block + 1}).background_color = light_aqua;

    console_handle.update_screen();
    ///clear cursor coz it will change
    console_handle.get_pixel(cursor_position).background_color = black;

    ///clear cursor coz it will change
    console_handle.get_pixel({getHeight() + 1, current_block + 1}).background_color = black;
}

void win_console::edit::run_sim() {
    board game(*this);
    while (2 > 1) {


        for (unsigned i = 0; i < getHeight(); i++) {
            for (unsigned j = 0; j < getWidth(); j++) {
                console_handle.set_pixel({i, j}, game.get_cell_icon({i, j}));
            }
        }
        console_handle.update_screen();

        game.iterate();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (!game.goal_cells_left()) {

            std::wcout << cc(yellow, black) << "press to continue... ";
            get_key();
            return;
        }
    }
}

void win_console::edit::set_additional_info() {

    system("cls");

    std::wcout << "\nlevel name :";
    std::cin >> level_name;

    std::wcout << "\nauthor :";
    std::cin >> author;

    std::wcout << "\nset level difficulty 1-4 : ";
    int temp_int;
    std::cin >> temp_int;

    if (temp_int >= 4) temp_int = 3;
    if (temp_int < 0) temp_int = 0;

    level_difficulty = (difficulty) temp_int;

    std::wcout << "\nmax iterations  :";
    std::cin >> temp_int;

    if (temp_int >= 999) temp_int = 999;
    if (temp_int < 0) temp_int = 0;
    max_iteration = temp_int;

    std::wcout << "\nmax piece cost  :";
    std::cin >> temp_int;

    if (temp_int >= 999) temp_int = 999;
    if (temp_int < 0) temp_int = 0;
    max_piece_cost = temp_int;


    std::wcout << "\n max number of pawns that user has at his disposal :\n";

    for (int i = 0; i < number_of_pawns.size(); i++) {
        std::wcout << "max amount of  ";
        std::wcout << cc(all_blocks[i]->get_unicode().text_color, black);
        std::wcout << all_blocks[i]->get_unicode().image << "  ";

        std::cin >> temp_int;

        if (temp_int >= 999) temp_int = 999;
        if (temp_int < 0) temp_int = 0;

        number_of_pawns[i] = temp_int;
    }
    std::wcout << "changes saved";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

}

unsigned char win_console::edit::get_key() {
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
