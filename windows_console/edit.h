//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EDIT_H
#define BLOCK_O_AUTOMATA_EDIT_H
#include "level_dir/level_edit.h"

namespace win_console {
class edit :public le::level_edit{
public:
    virtual void controlled_view();

    virtual void run_sim();

    void set_additional_info() override;

    virtual unsigned char get_key();
    };
}

#endif //BLOCK_O_AUTOMATA_EDIT_H
