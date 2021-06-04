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

    /// display win trophy
    if (level_beaten)
        console_handle.set_pixel({4, getWidth()}, {(wchar_t) 11201, purple, black});
    else
        console_handle.set_pixel({4, getWidth()}, {(wchar_t) 11201, gray, black});

    /// display blocks trophy
    if (max_piece_cost_beaten)
        console_handle.set_pixel({5, getWidth()}, {(wchar_t) 11202, yellow, black});
    else
        console_handle.set_pixel({5, getWidth()}, {(wchar_t) 11202, gray, black});

    /// display iterations trophy
    if (max_iteration_beaten)
        console_handle.set_pixel({6, getWidth()}, {(wchar_t) 11042, red, black});
    else
        console_handle.set_pixel({6, getWidth()}, {(wchar_t) 11042, gray, black});


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
    cursor_position.x--;
    bool activate_quit = false;
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
        console_handle.set_pixel({0, getWidth()}, {(wchar_t) 11164, red, black});

        /// display win trophy
        if (level_beaten)
            console_handle.set_pixel({4, getWidth()}, {(wchar_t) 11201, purple, black});
        else
            console_handle.set_pixel({4, getWidth()}, {(wchar_t) 11201, gray, black});

        /// display blocks trophy
        if (max_piece_cost_beaten)
            console_handle.set_pixel({5, getWidth()}, {(wchar_t) 11202, yellow, black});
        else
            console_handle.set_pixel({5, getWidth()}, {(wchar_t) 11202, gray, black});

        /// display iterations trophy
        if (max_iteration_beaten)
            console_handle.set_pixel({6, getWidth()}, {(wchar_t) 11042, red, black});
        else
            console_handle.set_pixel({6, getWidth()}, {(wchar_t) 11042, gray, black});


        key_pressed input = null;


        input = console_handle.await_key_press(std::chrono::milliseconds(200));

        switch (input) {
            case key_space:
            case key_enter:
                if (cursor_position == coord(0, getWidth()) && activate_quit) return 2;

        }

        ///display cursor
        console_handle.get_pixel(cursor_position).background_color = light_aqua;

        display_message();

        console_handle.update_screen();

        if (!game.goal_cells_left()) {
            system("cls");

            std::wcout << cc(yellow, black) << "u are winner!";
            level_beaten = true;
            if (game.get_counter() <= max_iteration)
                max_iteration_beaten = true;

            int empty_block_counter_origin = 0;
            int empty_block_counter_copy = 0;
            for (auto i:level)
                if (i->getCellType() == Empty)
                    if (!((empty_cell *) i)->isLocked())
                        empty_block_counter_copy++;
            for (auto i:original_level)
                if (i->getCellType() == Empty)
                    if (!((empty_cell *) i)->isLocked())
                        empty_block_counter_origin++;

            if (empty_block_counter_origin - empty_block_counter_copy <= max_piece_cost);
            max_piece_cost_beaten = true;

            std::swap(level, original_level);
            save();
            std::swap(level, original_level);
            get_key();
            return 1;
        }
        activate_quit = true;
    }
}

unsigned char win_console::play::get_key() {
    switch (console_handle.await_key_press()) {

        case key_enter:
            return 13;
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
        case key_a:
            return 'a';
        case key_w:
            return 'w';
        case key_s:
            return 's';
        case key_d:
            return 'd';
        case key_r:
            return 'r';

        default:

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

        case lp::lose:
            console_handle.set_message(red, black, L"you lost");
            break;
        case lp::win:
            console_handle.set_message(yellow, black, L"congratulations you won!");
            break;
        case lp::win_trofeum:
            console_handle.set_message(yellow, black, L"congratulations you won trofeum!");
            break;
            // todo display the range
        case lp::minimal_cost_trofeum:

            if (max_piece_cost_beaten)
                console_handle.set_message(blue, black, L"finishing level using minimal number of cells");
            else
                console_handle.set_message(blue, black, L"finish level using minimal number of cells");

            break;
        case lp::minimal_iterations_trofeum:
            if (max_iteration_beaten)
                console_handle.set_message(blue, black, L"finishing level in minimal number of iterations");
            else
                console_handle.set_message(blue, black, L"finish level in minimal number of iterations");
            break;
        case lp::none:

            break;
    }

    current_message = lp::none;
}
