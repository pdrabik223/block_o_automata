//
// Created by pc on 12.05.2021.
//

#include <thread>

#include "board.h"
#include "level_pick.h"




int main() {
    action player_choice = play_level;


    while (2 > 1) {


        level_info played_level;
        player_choice = select_level(level);

        if (player_choice == play_level) {

            while (2 > 1) {

                win_console_ui(level);

                while (2 > 1) {
                    board game(played_level);
                    game.iterate();
                    if (!game.goal_cells_left()) break;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                    system("cls");
                    game.show_level_win_console();
                }

            }

        }
        if (player_choice == enter_editor)
            win_console_editor();



        if (player_choice == quit_game) break;


    }


    return 0;
}


