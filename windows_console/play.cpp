//
// Created by studio25 on 20.05.2021.
//


#include "play.h"


void win_console::play::controlled_view() {

    for (unsigned i = 0; i < getHeight(); i++) {
        for (unsigned j = 0; j < getWidth(); j++) {
         console_handle.set_pixel({i, j}, get_cell(i, j).get_unicode());

        }

    }
    /// display cursor on screen
    console_handle.get_pixel(cursor_position).background_color = light_aqua;


    console_handle.set_pixel({getHeight(), 0}, {L" ", white, black});

    for (unsigned i = 0; i < all_blocks.size(); i++) {
        console_handle.set_pixel({getHeight(), i + 1}, all_blocks[i]->get_unicode());
        console_handle.get_pixel({getHeight(), i + 1}).image += L" ";
   }

    /// display cursor on screen
    console_handle.get_pixel({getHeight(), current_block + 1}).background_color = light_aqua;
    console_handle.update_screen();



}

int win_console::play::run_sim() {

    board game(*this);
    while (2 > 1) {

        game.iterate();
        if (!game.goal_cells_left()) {
            std::wcout << cc(yellow, black) << "congratulations, u won!";
            get_key();
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");

        for (unsigned h = 0; h < getHeight(); h++) {
            for (unsigned w = 0; w < getWidth(); w++) {

                color text_color = game.get_cell_icon({h, w}).text_color;
                color background_color = black;
                game.get_cell_icon({h, w});
                std::wcout << cc(text_color, background_color) << game.get_cell_icon({h, w}).image;

            }
        }
    }
}

unsigned char win_console::play::get_key() {
    return getch();
}
