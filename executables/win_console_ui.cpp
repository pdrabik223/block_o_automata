//
// Created by pc on 12.05.2021.
//

#include <thread>
#include <windows_console/edit.h>
#include <windows_console/pick.h>
#include <windows_console/play.h>

#include "board.h"


int main() {
    lc::player_action player_choice = lc::play_level;


    win_console::pick main_menu;

    while (1 < 2) {
        {
            level_info played_level;


            player_choice = main_menu.select_level();
            played_level = main_menu.get_level();


            if (player_choice == lc::play_level) {

                win_console::play game(played_level);
                game.main_loop();

            }

            if (player_choice == lc::enter_editor) {

                win_console::edit editor;
                editor.main_loop();
            }

            if (player_choice == lc::quit_game) break;
        }
    }

    return 0;
}


