//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_PICK_H
#define BLOCK_O_AUTOMATA_PICK_H

#include "level_dir/level_pick.h"

namespace win_console {
    class pick : public lc::level_pick {
    public:
        pick() : lc::level_pick() {}

        void display_ui() override;

        unsigned char get_key() override;

    };
}

#endif //BLOCK_O_AUTOMATA_PICK_H
