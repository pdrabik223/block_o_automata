//
// Created by pc on 08.05.2021.
//

#include "windows_console_tools/win_colors.h"

#include <string>
#include <iostream>


#include <windows.h>
#include <vector>
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))



#include <string>
#include <iostream>
#include <filesystem>

#include <windows.h>
#include <conio.h>

typedef std::vector<std::string> stringvec;

void ui(stringvec &v);

void read_directory(const std::string &name, stringvec &v) {
    std::string pattern(name);
    pattern.append("\\*");
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

    read_directory("C:\\Users\\pc\\Documents\\block_o_automata\\levels", v);

    ui(v);

}
// todo better key presses
//  arrows to move around
//  enter and esc
void ui(stringvec &v) {
    int i = 0;
    char k;
    while (2 > 1) {
        system("cls");
        std::cout<<std::endl;
        for (int j = 0; j < v.size(); j++) {

            if (i == j) {
                std::cout << cc(red, gray) <<" "<< j << ".   ";
                std::cout << cc(yellow, gray) << v[j] << std::endl;
                std::cout << cc(white,black);
            } else {
                std::cout << cc(red, black) << j << ".   ";
                std::cout << cc(yellow, black) << v[j] << std::endl;
                std::cout << cc(white,black);
            }
        }
  //      WAIT(50);
        k = getch();
        switch (k) {
            case 'w':
                --i;
                if (i < 0) i = v.size() - 1; // keep i in range of vector
                break;
            case 's':
                ++i;
                if (i >= v.size()) i = 0;
                break;
            case 'r':
                v.clear();
                read_directory("C:\\Users\\pc\\Documents\\block_o_automata\\levels", v);
                break;
            case 'q':
            case 27:
                return;
            case 13:
                std::cout<<cc(red)<<"u chosen "<<i;
                break;
            default:
                break;
        }

    }

}