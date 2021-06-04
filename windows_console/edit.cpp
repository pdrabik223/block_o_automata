//
// Created by studio25 on 20.05.2021.
//

#include "edit.h"

void win_console::edit::controlled_view() {

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


    /// display save icon a.k.a \/
    if (level_name == "noname") console_handle.set_pixel({2, getWidth()}, {(wchar_t) 11167, gray, black});
    else console_handle.set_pixel({2, getWidth()}, {(wchar_t) 11167, blue, black});



    /// display info icon a.k.a. little blue i on the right bottom
    console_handle.set_pixel({getHeight(), getWidth()}, {'i', blue, black});


    /// display width controls:
    console_handle.set_pixel({getHeight() - 2, getWidth()}, {'-', yellow, black});
    console_handle.set_pixel({getHeight() - 1, getWidth()}, {'+', yellow, black});


    /// display height controls:
    console_handle.set_pixel({getHeight(), getWidth() - 2}, {'-', yellow, black});
    console_handle.set_pixel({getHeight(), getWidth() - 1}, {'+', yellow, black});


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
/// todo complete run sim
///  we need better press to continue
///  but we need it everywhere
///  we need iteration counter
///  display blocks amounts
///todo all around code strengthening

void win_console::edit::run_sim() {
    board game(*this);
   console_handle.resize(getHeight()+1,getWidth()+1);
   cursor_position.x+=2;
    bool activate_quit = false;

    while (2 > 1) {

        /// clear buffer before overwriting it
        console_handle.clear();

        for (unsigned i = 0; i < getHeight(); i++) {
            for (unsigned j = 0; j < getWidth(); j++) {
                console_handle.set_pixel({i, j}, game.get_cell_icon({i, j}));
            }
        }
        /// display quit icon a.k.a. little red < in the right top corner
        console_handle.set_pixel({0, getWidth()}, {(wchar_t) 11164, red, light_aqua});

        key_pressed input = null;

        input = console_handle.await_key_press(std::chrono::milliseconds(250));

        switch (input) {
            case key_space:
            case key_enter:
                if ( activate_quit) {
                    return;
                }

        }

        current_message = le::exit;
        display_message();


        console_handle.update_screen();

        game.iterate();


        activate_quit = true;
    }
}

void win_console::edit::set_additional_info() {

    system("cls");
    std::wcout << cc(blue, black);
    std::wcout << "\nlevel name :";
    std::cin >> level_name;

    std::wcout << "\nauthor :";
    std::cin >> author;

    int temp_int;

    std::wcout << cc(yellow, black);
    std::wcout << "\nmax iterations  :";
    std::cin >> temp_int;

    if (temp_int >= 99) temp_int = 99;
    if (temp_int < 0) temp_int = 0;
    max_iteration = temp_int;

    std::wcout << "\nmax piece cost  :";
    std::cin >> temp_int;

    if (temp_int >= 99) temp_int = 99;
    if (temp_int < 0) temp_int = 0;
    max_piece_cost = temp_int;


    std::wcout << cc(yellow, black);

    system("cls");
    std::wcout << "changes saved";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

}

unsigned char win_console::edit::get_key() {
    switch (console_handle.await_key_press()) {
        case key_space:
            return 32;
        case key_enter:
            return 13;
        case key_delete:
            return 127;
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
        case key_x:
            return 'x';
        default:
            assert(false);
            return '\0';
    }
}

void win_console::edit::display_message() {
    switch (current_message) {
        case le::exit:
            console_handle.set_message(red, black, L"exit");
            break;

        case le::start_simulation:
            console_handle.set_message(yellow, black, L"run simulation");
            break;
        case le::save_changes_to_file:
            console_handle.set_message(blue, black, L"save current changes");
            break;
        case le::additional_info_request:
            console_handle.set_message(red, black, L"additional info is needed ");
            break;
        case le::increase_width:
            console_handle.set_message(yellow, black, L"increase width of the playing field");
            break;
        case le::increase_height:
            console_handle.set_message(yellow, black, L"increase height of the playing field");
            break;
        case le::decrease_width:
            console_handle.set_message(yellow, black, L"decrease width of the playing field");
            break;
        case le::decrease_height:
            console_handle.set_message(yellow, black, L"decrease height of the playing field");
            break;
        case le::additional_info:
            console_handle.set_message(blue, black, L"input additional info");
            break;
        case le::none:
            break;

    }
            current_message = le::none;
}
