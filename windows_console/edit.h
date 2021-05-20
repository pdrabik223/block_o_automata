//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EDIT_H
#define BLOCK_O_AUTOMATA_EDIT_H

#include "level_dir/level_edit.h"

namespace win_console {
    class edit : public le::level_edit {
    public:
        void controlled_view() override;

        void run_sim() override;

        void set_additional_info() override;

        unsigned char get_key() override;
    };
}

#endif //BLOCK_O_AUTOMATA_EDIT_H
