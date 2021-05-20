//
// Created by pc on 13.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_PLAY_H
#define BLOCK_O_AUTOMATA_LEVEL_PLAY_H


#include <conio.h>
#include "level_info.h"

#define ERROR(x) std::wcout << cc(red, black) << "\n error, "<<x<< cc(white, black)<<std::endl
namespace lp {
    enum player_action {
        nothing,
        quit_game,
        run_simulation

    };

    class level_play : public level_info {
    public:
        level_play() : level_info() {}

        level_play(const level_info &other) : level_info(other) {}

        player_action main_loop();

        void controlled_view();

        int run_sim();

        player_action analyze_movement(char key);

    private:

        int current_block = 0;

        coord cursor_position = {0, 0};

        std::array<cell *, 7> all_blocks = {new barrier_cell(),
                                            new barrier_cell(true),
                                            new move_cell(),
                                            new kill_cell(),
                                            new turn_cell(),
                                            new spawn_cell(),
                                            new goal_cell()};

    };
}

#endif //BLOCK_O_AUTOMATA_LEVEL_PLAY_H
