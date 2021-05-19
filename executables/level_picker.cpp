//
// Created by pc on 08.05.2021.
//
#include "level_dir/level_pick.h"


int main() {
    level_info level;
    lc::level_pick cos;
    lc::player_action command;
    command = cos.select_level();
    level = cos.get_level();


    _setmode(_fileno(stdout), _O_U16TEXT);
    if (command == lc::play_level)
        std::wcout << "\nchosen_level:\n" << level.get_info();
    if (command == lc::enter_editor)
        std::wcout << "\nenter editor";


    getch();

    return 0;
}
