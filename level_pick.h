//
// Created by pc on 12.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_PICK_H
#define BLOCK_O_AUTOMATA_LEVEL_PICK_H

#include "level_info.h"

enum action {
    play_level,
    enter_editor,
    quit_game
};
typedef std::vector<std::string> stringvec;

typedef std::vector<level_info> levelvec;

#include "windows_console_tools/win_colors.h"


#include <string>
#include <iostream>


#include <windows.h>
#include <vector>
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

#include <conio.h>

std::string ui(std::string &directory_path);

void load_levels(stringvec &file_paths, levelvec &levels, std::string& directory_path);

void read_directory(const std::string &name, stringvec &v);

action select_level(level_info &level);


#endif //BLOCK_O_AUTOMATA_LEVEL_PICK_H
