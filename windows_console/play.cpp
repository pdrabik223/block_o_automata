//
// Created by studio25 on 20.05.2021.
//


#include "play.h"


void win_console::play::controlled_view() {

    _setmode(_fileno(stdout), _O_U16TEXT);
    system("cls");

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            color text_color = get_cell(i, j).get_unicode().icon_color;

            color background_color = black;

            if (cursor_position == coord(i, j))
                background_color = light_aqua;
            std::wcout << cc(text_color, background_color) << get_cell(i, j).get_unicode().image;


        }
        std::wcout << "\n";
    }
    for (unsigned i = 0; i < all_blocks.size(); i++) {
        if (i == current_block) std::wcout << cc(all_blocks[i]->get_unicode().icon_color, light_yellow);
        else std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);

        std::wcout << "  " << all_blocks[i]->get_unicode().image;
        std::wcout << cc(white, black);
    }
    std::wcout << "\n";
}

int win_console::play::run_sim() {

    board game(*this);
    while (2 > 1) {

        game.iterate();
        if (!game.goal_cells_left()) {
            std::wcout<<cc(yellow,black)<<"congratulations, u won!";
            get_key();
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");

        for (unsigned h = 0; h < getHeight(); h++) {
            for (unsigned  w = 0; w < getWidth(); w++) {

                color text_color = game.get_cell_icon({h , w}).icon_color;
                color background_color = black;
                game.get_cell_icon({h , w});
                std::wcout << cc(text_color, background_color) << game.get_cell_icon({h , w}).image;

            }
            std::wcout << "\n";
        }
        std::wcout << "\n\n";
    }
}

unsigned char win_console::play::get_key() {
    return getch();
}
