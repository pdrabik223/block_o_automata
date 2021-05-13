//
// Created by pc on 08.05.2021.
//
#include "level_dir/level_pick.h"



int main() {
    level_info level;
    lc::level_pick cos(level);
    cos.select_level();

    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wcout<<"\nchosen_level:\n"<<level.get_info();

    getch();

    return 0;
}
