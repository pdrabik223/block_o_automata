//
// Created by pc on 13.05.2021.
//


#include <thread>
#include "level_play.h"

using namespace lp;

player_action level_play::main_loop() {

    ///lock the  original level state
    original_level = level;

    char key_pressed = 0;
    player_action operation;

    while (2 > 1) {

        controlled_view();

        key_pressed = get_key();

        operation = analyze_movement(key_pressed);
        if (operation == quit_game)
            return quit_game;

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
        case 13:

            // set pawn in place
            if (cursor_position.x < getHeight() && cursor_position.y < getWidth()) {
                /// if the cell was originally empty
                if (*original_level[cursor_position.toUint(getWidth())] == Empty) {
                    /// and was assignable
                    if (!((empty_cell *) original_level[cursor_position.toUint(getWidth())])->isLocked()) {



                            copy_cell(cursor_position, all_blocks[current_block]);


                    } else
                        current_message = cant_place_block_here;
                } else
                    current_message = cant_place_block_here;
            }

            /// if cursor is on "red < icon"
            if (cursor_position == coord(0, getWidth())) {

                return quit_game;
            }

            /// if cursor is on "yellow >icon"
            if (cursor_position == coord(1, getWidth())) {
                return run_simulation;
            }

            /// if cursor is on "win trophy"
            if (cursor_position == coord(4, getWidth())) {
                current_message = none;
            }
            /// if cursor is on "blocks trophy"
            if (cursor_position == coord(5, getWidth())) {
                current_message = minimal_cost_trofeum;
            }
            /// if cursor is on "iterations trophy"
            if (cursor_position == coord(6, getWidth())) {
                current_message = minimal_iterations_trofeum;
            }


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
        case 'x':
            copy_cell(cursor_position, original_level[cursor_position.toUint(getWidth())]);
            break;
        default:
            return nothing;

    }
    if (cursor_position.y > getWidth()) cursor_position.y = getWidth();
    if (cursor_position.x >= getHeight()) cursor_position.x = getHeight() - 1;

    if (cursor_position.y < 0) cursor_position.y = 0;
    if (cursor_position.x < 0) cursor_position.x = 0;

    /// if cursor is on "red < icon"
    if (cursor_position == coord(0, getWidth())) {
        current_message = exit;
    }

        /// if cursor is on "yellow >icon"
    else if (cursor_position == coord(1, getWidth())) {
        current_message = start_simulation;
    }


    return nothing;
}

