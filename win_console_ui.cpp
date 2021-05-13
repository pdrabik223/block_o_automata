//
// Created by pc on 12.05.2021.
//

#include <thread>

#include "board.h"
#include "level_dir/level_pick.h"
#include "level_dir/level_edit.h"
#include "level_dir/level_play.h"


int main() {
    lc::action player_choice = lc::play_level;


    while (2 > 1) {

        level_info played_level;
        lc::level_pick chose_for_directory(played_level);
        player_choice = chose_for_directory.select_level();

        if (player_choice == lc::play_level) {

            while (2 > 1) {

                lp::level_play game(played_level);
                if(game.main_loop() == lp::quit_game ) return 0;

            }

        }
        if (player_choice == lc::enter_editor) {
            le::level_edit edytor;
            edytor.main_loop();
        }

        if (player_choice == lc::quit_game) break;


    }


    return 0;
}


