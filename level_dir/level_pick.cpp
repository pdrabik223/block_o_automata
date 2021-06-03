//
// Created by pc on 12.05.2021.
//

#include "level_pick.h"

using namespace lc;

player_action level_pick::select_level() {

    loaded_levels = {};

    player_action command = ui();

    if (command == quit_game) return quit_game;
    else if (command == enter_editor) return enter_editor;

    load(directory_path + loaded_levels[cursor_position]);

    return play_level;
}


player_action level_pick::ui() {

    levelvec levels;

    read_directory(directory_path, loaded_levels);

    load_levels(loaded_levels, levels, directory_path);

    unsigned char k;

    while (2 > 1) {

        display_ui();

        k = get_key();


        switch (k) {
            case 'w':
                --cursor_position;
                if (cursor_position < 0)
                    cursor_position = levels.size() + 1; // keep cursor_position in (range of vector +1)
                break;

            case 's':
                ++cursor_position;
                if (cursor_position > levels.size() + 1) cursor_position = 0;

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
                else if (cursor_position == loaded_levels.size()) return enter_editor;

                else if (cursor_position == loaded_levels.size()+1) return quit_game;

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