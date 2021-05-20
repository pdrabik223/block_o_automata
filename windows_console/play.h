//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_PLAY_H
#define BLOCK_O_AUTOMATA_PLAY_H

#include <thread>
#include <board.h>

#include <level_dir/level_play.h>

namespace win_console {

    class play : public lp::level_play {

    public:
       play() : lp::level_play() {};

        play(const level_info &other) : lp::level_play(other) {};

        void controlled_view() override;

        int run_sim() override;

        unsigned char get_key() override;
    };
}

#endif //BLOCK_O_AUTOMATA_PLAY_H
