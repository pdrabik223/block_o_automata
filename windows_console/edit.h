//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EDIT_H
#define BLOCK_O_AUTOMATA_EDIT_H

#include "level_dir/level_edit.h"
#include "scml.h"

namespace win_console {
    class edit : public le::level_edit {
    public:
        edit():le::level_edit(), console_handle(10+1, 10 + 3) {};

        void controlled_view() override;

        void run_sim() override;

        void set_additional_info() override;

        unsigned char get_key() override;
    protected:
        scml console_handle;
    };
}

#endif //BLOCK_O_AUTOMATA_EDIT_H
