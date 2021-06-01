//
// Created by pc on 13.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_PLAY_H
#define BLOCK_O_AUTOMATA_LEVEL_PLAY_H


#include <conio.h>
#include "level_info.h"

namespace lp {
    enum player_action {
        nothing,
        quit_game,
        run_simulation
    };

    enum message{
        none,
        exit,
        start_simulation,
        cant_place_block_here,
        no_more_blocks_left,
        lose,
        win,
        win_trofeum,
        minimal_cost_trofeum,
        minimal_iterations_trofeum

    };


    class level_play : public level_info {
    public:
        level_play() : level_info() {}

        level_play(const level_info &other) : level_info(other) {

        }

        player_action main_loop();

        player_action analyze_movement(char key);

        virtual void controlled_view(){};

        virtual int run_sim(){
            assert(false);
            return -1;
        };

        virtual unsigned char get_key(){
            assert(false);
            return -1;
        };

    protected:
        unsigned  current_block = 0;

        message current_message = none;

        coord cursor_position = {0, 0};

        std::array<cell *, 5> all_blocks = {new barrier_cell(),
                                            new barrier_cell(true),
                                            new move_cell(up),
                                            new turn_cell(up),
                                            new spawn_cell(up)};
        std::vector<cell *> original_level;

    };
}

#endif //BLOCK_O_AUTOMATA_LEVEL_PLAY_H
