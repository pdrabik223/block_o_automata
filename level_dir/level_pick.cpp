//
// Created by pc on 12.05.2021.
//

#include "level_pick.h"
using namespace lc;
player_action level_pick::select_level() {

    stringvec v;
    levelvec l;

    std::string path;

    path = ui();

    if (path == "quit") return quit_game;
    else if(path == "creator") return enter_editor;

    load(directory_path + path);

    return play_level;
}




std::string level_pick::ui() {

    levelvec levels;
    stringvec v;

    read_directory(directory_path, v);

    load_levels(v, levels, directory_path);

    int i = 0;

    char k;

    while (2 > 1) {
        system("cls");
        std::cout << std::endl;
        int j = 0;
        for (; j < levels.size(); j++) {

            if (i == j) {
                std::cout << cc(red, gray) << " " << j << ".   ";
                std::wcout << cc(yellow, gray) << levels[j].get_info();
                std::cout << cc(white, black);
            } else {
                std::cout << cc(red, black) << j << ".   ";
                std::wcout << cc(yellow, black) << levels[j].get_info();
                std::cout << cc(white, black);
            }
        }

        if (i == levels.size()) {

            std::cout << cc(red, gray) << " " << j << ".   ";
            std::wcout << cc(yellow, gray) << "create level...";
            std::cout << cc(white, black);

        } else {

            std::cout << cc(red, black) << j << ".   ";
            std::wcout << cc(yellow, black) << "create level...";
            std::cout << cc(white, black);
        }

        k = getch();

        switch (k) {
            case 'w':
                --i;
                if (i < 0) i = levels.size(); // keep i in (range of vector +1)
                break;


            case 's':
                ++i;
                if (i > levels.size()) i = 0;

                break;
            case 'r':

                levels.clear();
                v.clear();

                read_directory(directory_path, v);

                load_levels(v, levels, directory_path);
                break;

            case 'q':
            case 27:
                return "quit";

            case 'e':
            case 13:
                if (i < v.size())
                    return v[i];
                else return "creator";
            default:
                break;
        }

    }

}

level_info level_pick::get_level() {
    return level_info(*this);
}


void read_directory(const std::string &name, stringvec &v) {
    std::string pattern(name);
    pattern.append("*.txt");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {

        do {
            v.push_back(data.cFileName);
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);

    }
}

void load_levels(stringvec &file_paths, levelvec &levels, std::string &directory_path) {

    for (auto i:file_paths) {
        levels.push_back(level_info());
        levels.back().load(directory_path + i);
    }
}