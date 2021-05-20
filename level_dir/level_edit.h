//
// Created by pc on 13.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_EDIT_H
#define BLOCK_O_AUTOMATA_LEVEL_EDIT_H

#include <iostream>
#include <conio.h>
#include <thread>
#include "../board.h"
#include "level_info.h"

#define ERROR(x) std::wcout << cc(red, black) << "\n error, "<<x<< cc(white, black)<<std::endl
namespace le {
    enum player_action {
        nothing,
        quit_edit,
        run_simulation,
        set_info

    };

    class level_edit: public level_info {
    public:
        level_edit() : level_info(10, 10) {}

        void main_loop();

        void controlled_view();

        player_action analyze_movement(char key);

        int run_sim();

        void set_additional_info();

    private:

        int current_block = 0;

        coord cursor_position = {0, 0};
        std::array<cell *, 7> all_blocks = {new barrier_cell(),
                                            new barrier_cell(true),
                                            new move_cell(up),
                                            new kill_cell(),
                                            new turn_cell(up),
                                            new spawn_cell(up),
                                            new goal_cell()};

    };
}
#endif //BLOCK_O_AUTOMATA_LEVEL_EDIT_H
