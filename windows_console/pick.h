//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PICK_H_
#define BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PICK_H_

#include "level_dir/level_pick.h"

namespace win_console {
    class Pick : public lc::LevelPick {
    public:
      Pick() : lc::LevelPick() {    _setmode(_fileno(stdout), _O_U16TEXT);
        }

        void DisplayUi() override;

        unsigned char GetKey() override;

    };
}

#endif // BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_PICK_H_
