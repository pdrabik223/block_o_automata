//
// Created by pc on 08.05.2021.
//

#include "windows_console_tools/win_colors.h"
#include "level_info.h"

#include <string>
#include <iostream>


#include <windows.h>
#include <vector>
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))


#include <conio.h>

typedef std::vector<std::string> stringvec;
typedef std::vector<level_info> levelvec;

void ui(levelvec &levels);

void load_levels(stringvec &file_paths, levelvec &levels);

void read_directory(const std::string &name, stringvec &v) {
    std::string pattern(name);
    pattern.append("\\*.txt");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {

        do {
            v.push_back(data.cFileName);
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);

    }
}


int main() {
    stringvec v;
    levelvec l;

    level_info new_level;
    new_level.level_beaten=true;
    new_level.max_piece_cost_beaten=false;
    new_level.max_iteration_beaten = true;
    new_level.save();



    read_directory("C:\\Users\\pc\\Documents\\block_o_automata\\levels", v);

    load_levels(v, l);


    ui(l);


}

void load_levels(stringvec &file_paths, levelvec &levels) {
    std::string directory_path = "C:\\Users\\pc\\Documents\\block_o_automata\\levels\\";
    levels.clear();
    for (auto i:file_paths) {
        levels.push_back(level_info());
        levels.back().load(directory_path + i);
    }
}

// todo better key presses
//  arrows to move around
//  enter and esc
void ui(levelvec &levels) {
    stringvec v;
    int i = 0;
    char k;
    while (2 > 1) {
        //  system("cls");
        std::cout << std::endl;
        for (int j = 0; j < levels.size(); j++) {

            if (i == j) {
                std::cout << cc(red, gray) << " " << j << ".   ";
                std::wcout << cc(yellow, gray) << levels[j].get_info() ;
                std::cout << cc(white, black);
            } else {
                std::cout << cc(red, black) << j << ".   ";
                std::wcout << cc(yellow, black) << levels[j].get_info() ;
                std::cout << cc(white, black);
            }
        }
        //      WAIT(50);
        k = getch();
        switch (k) {
            case 'w':
                --i;
                if (i < 0) i = levels.size() - 1; // keep i in range of vector
                break;
            case 's':
                ++i;
                if (i >= levels.size()) i = 0;
                break;
            case 'r':
                levels.clear();
                v.clear();
                read_directory("C:\\Users\\pc\\Documents\\block_o_automata\\levels", v);
                load_levels(v,levels);
                break;
            case 'q':
            case 27:
                return;
            case 13:
                std::cout << cc(red) << "u chosen " << i;
                break;
            default:
                break;
        }

    }

}