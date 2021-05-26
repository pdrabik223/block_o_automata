//
// Created by pc on 13.05.2021.
//


#include <thread>
#include "level_play.h"

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

    }
    if (cursor_position.y >= getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = getHeight() - 1;
    return nothing;
}

