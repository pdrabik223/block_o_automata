//
// Created by pc on 12.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_PICK_H
#define BLOCK_O_AUTOMATA_LEVEL_PICK_H

#include "level_info.h"
#include "../windows_console_tools/win_colors.h"

#include <string>
#include <iostream>

#include <Windows.h>
#include <vector>
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

#include <conio.h>

typedef std::vector<std::string> stringvec;

typedef std::vector<level_info> levelvec;

void read_directory(const std::string &name, stringvec &v);

void load_levels(stringvec &file_paths, levelvec &levels, std::string &directory_path);


namespace lc {
    enum action {
        play_level,
        enter_editor,
        quit_game
    };



    class level_pick {
    public:

        level_pick(level_info &level) {
            this->level = &level;
        }

        action select_level();

    private :
        std::string ui();

        std::string directory_path = "C:\\Users\\pc\\Documents\\block_o_automata\\levels\\";
        level_info *level;
    };

}
#endif //BLOCK_O_AUTOMATA_LEVEL_PICK_H
