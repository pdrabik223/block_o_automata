//
// Created by pc on 13.05.2021.
//


#include <thread>
#include "level_play.h"
#include "../board.h"
using namespace lp;
player_action level_play::main_loop() {

    char key_pressed = 0;
    player_action operation;

    while (2 > 1) {

        controlled_view();

        key_pressed = get_key();

        operation = analyze_movement(key_pressed);
        if (operation == quit_game) return quit_game;
        if (operation == run_simulation) run_sim();

    }

}

void level_play::controlled_view() {
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

int level_play::run_sim() {


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

player_action level_play::analyze_movement(char key) {
    switch (key) {
        case 'a':
            cursor_position.y--;
            break;
        case 'w':
            cursor_position.x--;
            break;
        case 's':
            cursor_position.x++;
            break;
        case 'd':
            cursor_position.y++;
            break;
        case 32:
            return run_simulation;
        case 'q':
            return quit_game;

        case 13:
            // set pawn in place
            set_cell(cursor_position, all_blocks[current_block]);
            break;
        case 'r':

            operator[](cursor_position)->rotateRight();

            break;
        case '1':
            current_block = 0;
            break;
        case '2':
            current_block = 1;
            break;
        case '3':
            current_block = 2;
            break;
        case '4':
            current_block = 3;
            break;
        case '5':
            current_block = 4;
            break;
        case '6':
            current_block = 5;
            break;
        default:
            return nothing;
            break;
    }
    if (cursor_position.y >= getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = getHeight() - 1;
    return nothing;
}

unsigned char level_play::get_key() {
    return getch();
}
