//
// Created by pc on 08.05.2021.
//

#include "windows_console_tools/win_colors.h"

#include <string>
#include <iostream>


#include <windows.h>
#include <vector>


#include <string>
#include <iostream>
#include <filesystem>

#include <windows.h>
typedef std::vector<std::string> stringvec;

void read_directory(const std::string& name, stringvec& v)
{
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



int main()
{
    stringvec v;
    read_directory("C:\\Users\\pc\\Documents\\block_o_automata\\levels", v);

    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<std::endl;

    }
}
