//
// Created by pc on 08.05.2021.
//
#include "level_pick.h"



int main() {


    level_info level;
    std::string dir_path = "C:\\Users\\pc\\Documents\\block_o_automata\\levels";

    std::string path;

    path = ui(dir_path);

    if (path == "quit") return 1;
    else if(path == "creator") return 2;

    dir_path.append("\\\\");

    level.load((dir_path + path));

    std::cout<<"\nchosen_level:\n";

    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wcout<<level.get_info();

    getch();

    return 0;
}
