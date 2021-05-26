//
// Created by pc on 13.05.2021.
//

#include "level_edit.h"

using namespace le;


player_action level_edit::analyze_movement(char key) {
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
            return quit_edit;
        case 'i':
            return set_info;
        case 13:
            // set pawn in place
            if (cursor_position.x < getHeight() && cursor_position.y < getWidth())
                copy_cell(cursor_position, all_blocks[current_block]);
            else {
                if (cursor_position.x == getHeight()) {
                    if (cursor_position.y == getWidth() - 1) {

                        resize(getWidth() , getHeight() + 1);
                        cursor_position.x++;

                    } else if (cursor_position.y == getWidth() - 2) {
                        resize(getWidth(), getHeight() - 1);
                        cursor_position.x--;
                    }
                }

                if (cursor_position.y == getWidth()) {
                    if (cursor_position.x == getHeight() - 1) {
                        resize(getWidth() + 1, getHeight());
                        cursor_position.y++;

                    } else if (cursor_position.x == getHeight() - 2) {
                        resize(getWidth() -1 , getHeight());
                        cursor_position.y--;
                    }
                }

            }
            break;
        case 'r':
            level[cursor_position.toUint(getWidth())]->rotateRight();
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
        case '7':
            current_block = 6;
            break;
        case '8':
            current_block = 7;
            break;

        default:
            return nothing;
            break;
    }


    if (cursor_position.y > getWidth()) cursor_position.y = getWidth();
    if (cursor_position.x > getHeight()) cursor_position.x = getHeight();

    if (cursor_position.y < 0) cursor_position.y = 0;
    if (cursor_position.x < 0) cursor_position.x = 0;

    return nothing;
}


void level_edit::main_loop() {

    char key_pressed = 0;
    player_action operation;

    while (2 > 1) {
        controlled_view();

        key_pressed = get_key();

        operation = analyze_movement(key_pressed);

        if (operation == quit_edit) break;
        if (operation == run_simulation) run_sim();
        if (operation == set_info) set_additional_info();

    }
    save();
}



