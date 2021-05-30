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
        case 13:
            // set pawn in place
            if (cursor_position.x < getHeight() && cursor_position.y < getWidth())
                copy_cell(cursor_position, all_blocks[current_block]);
            else {


                /// if cursor is on " plus on the right"
                if (cursor_position == coord(getHeight() - 1, getWidth())) {
                    resize( getHeight(),getWidth() + 1);
                    cursor_position.y++;
                    /// i'm so sorry but I wanted to use it so much
                    /// and i know it's confusing so I couldn't
                    /// but here is quite clear
                    goto skip;
                }
                /// if cursor is on " minus on the right"
                if (cursor_position == coord(getHeight() - 2, getWidth())) {
                    resize( getHeight(),getWidth() - 1);
                    cursor_position.y--;
                    goto skip;
                }

                /// if cursor is on " plus on the bottom"
                if (cursor_position == coord(getHeight(), getWidth() - 1)) {
                    resize( getHeight()+1,getWidth() );
                    cursor_position.x++;
                    goto skip;
                }
                /// if cursor is on " minus on the bottom"
                if (cursor_position == coord(getHeight(), getWidth() - 2)) {
                    resize( getHeight()-1,getWidth() );
                    cursor_position.x--;
                    goto skip;
                }

                /// if cursor is on "blue  i icon"
                if (cursor_position == coord(getWidth(), getHeight())) {
                    set_additional_info();
                    goto skip;
                }

                /// if cursor is on "red < icon"
                if (cursor_position == coord(0, getHeight())) {
                    return quit_edit;
                }
                /// if cursor is on "blue \/ icon"
                if (cursor_position == coord(1, getHeight())) {
                   save();
                }

            }
        skip:
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

    }


    if (cursor_position.y >

        getWidth()

            )
        cursor_position.
                y = getWidth();
    if (cursor_position.x >

        getHeight()

            )
        cursor_position.
                x = getHeight();

    if (cursor_position.y < 0)
        cursor_position.
                y = 0;
    if (cursor_position.x < 0)
        cursor_position.
                x = 0;

    return
            nothing;
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
    //save();
}



