//
// Created by pc on 04.05.2021.
//

/// the first approach

#include "windows_console_tools/win_colors.h"



int main(){
    /// allow using chart in console
    _setmode(_fileno(stdout), _O_U16TEXT);


    std::wcout<<cc(gray)<<"barrier_cell\t"<<L"\x25A3\n";
    std::wcout<<cc(gray)<<"movable_barrier_cell\t"<<L"\x25A2\n";
    std::wcout<<cc(red)<<"kill_cell\t"<<L"\x2716\n";

    std::wcout<<cc(yellow)<<"move_cell\t"<<L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";

    std::wcout<<cc(green)<<"spawn_cell\t"<<L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";

    std::wcout<<cc(blue)<<"turn_cell\t"<<L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";


    std::wcout<<cc(purple)<<"turn_cell\t"<<L"\x2B24 \n";

    return 0;
}