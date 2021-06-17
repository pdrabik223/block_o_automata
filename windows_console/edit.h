//
// Created by studio25 on 20.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_EDIT_H_
#define BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_EDIT_H_

#include "level_dir/level_edit.h"
#include "scml.h"
#include <thread>

namespace win_console {
    class Edit : public le::LevelEdit {
    public:
      Edit() : le::LevelEdit(), console_handle_(GetHeight() + 3, GetWidth() + 2) {};

        void ControlledView() override;

        void RunSim() override;

        void SetAdditionalInfo() override;

        unsigned char GetKey() override;

    protected:
        void DisplayMessage();

        Scml console_handle_;
    };
}


#endif // BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_EDIT_H_
