//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_PLAY_H
#define BLOCK_O_AUTOMATA_PLAY_H

#include <thread>
#include <board.h>

#include <level_dir/level_play.h>
#include "scml.h"

namespace win_console {

    class play : public lp::level_play {

    public:
        play() : lp::level_play(), console_handle(10, 10 + 2) {};

        play(const level_info &other) : lp::level_play(other),
                                        console_handle(other.getWidth(), other.getHeight() + 2) {};

        void controlled_view() override;

        int run_sim() override;

        unsigned char get_key() override;

    protected:
        scml console_handle;
    };

}

#endif //BLOCK_O_AUTOMATA_PLAY_H
