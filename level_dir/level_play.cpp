//
// Created by pc on 13.05.2021.
//


#include <thread>
#include "level_play.h"
#include "../board.h"
using namespace lp;
player_action level_play::main_loop() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    char key_pressed = 0;
    player_action operation;

    while (2 > 1) {
        system("cls");

        controlled_view();

        key_pressed = getch();

        operation = analyze_movement(key_pressed);
        if (operation == quit_game) return quit_game;
        if (operation == run_simulation) run_sim();

    }

}

void level_play::controlled_view() {

    for (int i = 0; i < level->getHeight(); i++) {
        for (int j = 0; j < level->getWidth(); j++) {
            color text_color = level->get_cell(i, j).get_unicode().icon_color;

            color background_color = black;

            if (cursor_position == coord(i, j))
                background_color = light_aqua;
            std::wcout << cc(text_color, background_color) << level->get_cell(i, j).get_unicode().image;


        }
        std::wcout << "\n";
    }
    for (unsigned i = 0; i < all_blocks.size(); i++) {
        if (i == current_block)std::wcout << cc(all_blocks[i]->get_unicode().icon_color, light_yellow);
        else std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);

        std::wcout << "  " << all_blocks[i]->get_unicode().image;
        std::wcout << cc(white, black);
    }
    std::wcout << "\n";

}

int level_play::run_sim() {


    board game(*level);
    while (2 > 1) {

        game.iterate();
        if (!game.goal_cells_left()) return 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
        game.show_level_win_console();

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
            level->set_cell(cursor_position, all_blocks[current_block]);
            break;
        case 'r':

            (*level)[cursor_position]->rotateRight();

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
            ERROR("unknown key");
            break;


    }
    if (cursor_position.y >= level->getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= level->getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = level->getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = level->getHeight() - 1;
    return nothing;
}
