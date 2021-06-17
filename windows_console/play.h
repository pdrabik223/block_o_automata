//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PLAY_H_
#define BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PLAY_H_

#include <thread>
#include <board.h>

#include <level_dir/level_play.h>
#include "scml.h"

namespace win_console {

    class Play : public lp::LevelPlay {

    public:
      Play() : lp::LevelPlay(), console_handle_(10, 10 + 2) {};

      Play(const LevelInfo &other) : lp::LevelPlay(other),
            console_handle_(other.GetWidth(), other.GetHeight() + 2) {};

        void ControlledView() override;

        int RunSim() override;

        unsigned char GetKey() override;


    protected:
        void DisplayMessage();

        Scml console_handle_;

    };

}

#endif // BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PLAY_H_
