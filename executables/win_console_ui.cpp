//
// Created by pc on 12.05.2021.
//

#include <thread>
#include <windows_console/edit.h>
#include <windows_console/pick.h>
#include <windows_console/play.h>

#include "board.h"
#include "level_dir/level_pick.h"

#include "level_dir/level_play.h"


int main() {
    lc::player_action player_choice = lc::play_level;


    while (2 > 1) {

        level_info played_level;
        win_console::pick chose_for_directory;

        player_choice = chose_for_directory.select_level();
        played_level = chose_for_directory.get_level();


        if (player_choice == lc::play_level) {

            while (2 > 1) {

                win_console::play game(played_level);

                game.main_loop();
                if (game.main_loop() == lp::quit_game) return 0;
            }
        }

        if (player_choice == lc::enter_editor) {

            win_console::edit editor;
            editor.main_loop();
        }

        if (player_choice == lc::quit_game) break;

    }

    return 0;
}


