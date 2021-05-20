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


#include <conio.h>

typedef std::vector<std::string> stringvec;

typedef std::vector<level_info> levelvec;

void read_directory(const std::string &name, stringvec &v);

void load_levels(stringvec &file_paths, levelvec &levels, std::string &directory_path);


namespace lc {
    enum player_action {
        play_level,
        enter_editor,
        quit_game
    };


    class level_pick : public level_info {
    public:

        level_pick() : level_info() {}

        player_action select_level();

        level_info get_level();

        virtual void display_ui(){};

        virtual unsigned char get_key() {
            assert(false);
            return -1;
        };

    protected :
        /// player ui, it needs to be done better
        /// \return  path to chosen folder
        ///  or command to enter edit mode
        ///  or command to quit game
        player_action ui();

        unsigned cursor_position = 0;

        std::string directory_path = "../\\levels";
        stringvec loaded_levels = {};


    };

}
#endif //BLOCK_O_AUTOMATA_LEVEL_PICK_H
