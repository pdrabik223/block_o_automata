//
// Created by studio25 on 20.05.2021.
//

#include "edit.h"

void win_console::edit::controlled_view() {
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

        if (i == getHeight() - 2) {
            if (cursor_position.y == getWidth()) {
                if (cursor_position.x == getHeight() - 2)
                    std::wcout << cc(yellow, light_aqua) << "- ";
                else
                    std::wcout << cc(yellow, black) << "- ";

            } else std::wcout << cc(yellow, black) << "- ";
        }
        if (i == getHeight() - 1) {
            if (cursor_position.y == getWidth()) {
                if (cursor_position.x == getHeight() - 1)
                    std::wcout << cc(yellow, light_aqua) << "+ ";
                else
                    std::wcout << cc(yellow, black) << "+ ";
            } else
                std::wcout << cc(yellow, black) << "+ ";

        }
        std::wcout << cc(white, black) << "\n";
    }


    /// display height controls:
    /// get me in the middle of displayed plane
    for (unsigned i = 0; i < getWidth() - 2; i++) {
        std::wcout << "  ";
    }


    if (cursor_position.x == getHeight()) {

        if (cursor_position.y == getWidth() - 2) {
            std::wcout << cc(yellow, light_aqua) << "- ";
            std::wcout << cc(yellow, black) << "+ \n";
        } else if (cursor_position.y == getWidth() - 1) {
            std::wcout << cc(yellow, black) << "- ";
            std::wcout << cc(yellow, light_aqua) << "+ \n";
        } else std::wcout << cc(yellow, light_aqua) << "- +\n";


    } else {
        std::wcout << cc(yellow, black) << "- +\n";
    }

    /// display possible blocks
    for (unsigned i = 0; i < all_blocks.size(); i++) {
        if (i == current_block)std::wcout << cc(all_blocks[i]->get_unicode().icon_color, light_yellow);
        else std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);
        std::wcout << "  " << all_blocks[i]->get_unicode().image;
        std::wcout << cc(white, black);
    }

    std::wcout << "\n";
}

void win_console::edit::run_sim() {
    board game(*this);
    while (2 > 1) {

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
        for (unsigned h = 0; h < getHeight(); h++) {
            for (unsigned w = 0; w < getWidth(); w++) {

                color text_color = game.get_cell_icon({h, w}).icon_color;
                color background_color = black;
                game.get_cell_icon({h, w});
                std::wcout << cc(text_color, background_color) << game.get_cell_icon({h, w}).image;

            }
            std::wcout << "\n";
        }
        std::wcout << "\n";

        game.iterate();

        if (!game.goal_cells_left()) {

            std::wcout << cc(yellow, black) << "press to continue... ";
            get_key();
            return;
        }
    }
}

void win_console::edit::set_additional_info() {


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
        std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);
        std::wcout << all_blocks[i]->get_unicode().image << "  ";

        std::cin >> temp_int;

        if (temp_int >= 999) temp_int = 999;
        if (temp_int < 0) temp_int = 0;

        number_of_pawns[i] = temp_int;
    }
    std::wcout << "changes saved";
}

unsigned char win_console::edit::get_key() {
    return getch();
}
