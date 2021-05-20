//
// Created by pc on 12.05.2021.
//

#include "level_pick.h"

using namespace lc;

player_action level_pick::select_level() {

    player_action command= ui();

    if (command == quit_game) return quit_game;
    else if (command == enter_editor) return enter_editor;

    load(directory_path + loaded_levels[cursor_position]);

    return play_level;
}


player_action level_pick::ui() {

    levelvec levels;

    read_directory(directory_path, loaded_levels);

    load_levels(loaded_levels, levels, directory_path);


    char k;

    while (2 > 1) {

        display_ui();

        k = getch();


        switch (k) {
            case 'w':
                --cursor_position;
                if (cursor_position < 0)
                    cursor_position = levels.size(); // keep cursor_position in (range of vector +1)
                break;


            case 's':
                ++cursor_position;
                if (cursor_position > levels.size()) cursor_position = 0;

                break;
            case 'r':

                levels.clear();
                loaded_levels.clear();

                read_directory(directory_path, loaded_levels);

                load_levels(loaded_levels, levels, directory_path);
                break;

            case 'q':
            case 27:
                return quit_game;

            case 'e':
            case 13:
                if (cursor_position < loaded_levels.size())
                    return play_level;
                else return enter_editor;
            default:
                break;
        }

    }

}

level_info level_pick::get_level() {
    return level_info(*this);
}

void level_pick::display_ui() {

    levelvec levels;
    load_levels(loaded_levels, levels, directory_path);

    system("cls");
    std::cout << std::endl;

    int j;
    j = 0;
    for (; j < levels.size(); j++) {

        if (cursor_position == j) {
            std::cout << cc(red, gray) << " " << j << ".   ";
            std::wcout << cc(yellow, gray) << levels[j].get_info();
            std::cout << cc(white, black);
        } else {
            std::cout << cc(red, black) << j << ".   ";
            std::wcout << cc(yellow, black) << levels[j].get_info();
            std::cout << cc(white, black);
        }
    }

    if (cursor_position == levels.size()) {

        std::cout << cc(red, gray) << " " << j << ".   ";
        std::wcout << cc(yellow, gray) << "create level...";
        std::cout << cc(white, black);

    } else {

        std::cout << cc(red, black) << j << ".   ";
        std::wcout << cc(yellow, black) << "create level...";
        std::cout << cc(white, black);
    }
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