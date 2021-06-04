//
// Created by studio25 on 20.05.2021.
//

#include "pick.h"

void win_console::pick::display_ui() {

    levelvec levels;
    load_levels(loaded_levels, levels, directory_path);

    system("cls");


    int j;
    j = 0;
    for (; j < levels.size(); j++) {

        if (cursor_position == j) {
            std::wcout << cc(red, gray) << " " << j << ".   ";
            std::wcout << cc(yellow, gray) << levels[j].get_info();

            if(levels[j].level_beaten) std::wcout<<cc(purple,gray)<<L" "<< (wchar_t) 11201<<L"  ";
            else std::wcout<<cc(yellow,gray)<<L"    ";

            if(levels[j].max_piece_cost_beaten) std::wcout<<cc(yellow,gray)<<L" "<< (wchar_t) 11202<<L"  ";
            else std::wcout<<cc(yellow,gray)<<L"    ";

            if(levels[j].max_iteration_beaten) std::wcout<<cc(red,gray)<<L" "<< (wchar_t) 11042<<L"  ";
            else std::wcout<<cc(yellow,gray)<<L"    ";


            std::wcout << cc(white, black);
        } else {
            std::wcout << cc(red, black) << j << ".   ";
            std::wcout << cc(yellow, black) << levels[j].get_info();

            if(levels[j].level_beaten) std::wcout<<cc(purple,black)<<L" "<< (wchar_t) 11201<<L"  ";
            else std::wcout<<cc(yellow,black)<<L"    ";

            if(levels[j].max_piece_cost_beaten) std::wcout<<cc(yellow,black)<<L" "<< (wchar_t) 11202<<L"  ";
            else std::wcout<<cc(yellow,black)<<L"    ";

            if(levels[j].max_iteration_beaten) std::wcout<<cc(red,black)<<L" "<< (wchar_t) 11042<<L"  ";
            else std::wcout<<cc(yellow,black)<<L"    ";
            std::wcout << cc(white, black);
        }
        std::wcout <<L"\n";
    }

    if (cursor_position == levels.size()) {

        std::wcout << cc(red, gray) << " " << j << ".   ";
        std::wcout << cc(yellow, gray) << L"create level...\n";
        std::wcout << cc(white, black);

    } else {

        std::wcout << cc(red, black) << j << ".   ";
        std::wcout << cc(yellow, black) << L"create level...\n";
        std::wcout << cc(white, black);
    }

    if (cursor_position == levels.size()+1) {

        std::wcout << cc(red, gray) << " " << j+1 << ".   ";
        std::wcout << cc(yellow, gray) << L"exit game";
        std::wcout << cc(white, black);

    } else {

        std::wcout << cc(red, black) << j+1 << ".   ";
        std::wcout << cc(yellow, black) << L"exit game";
        std::wcout << cc(white, black);
    }

}

unsigned char win_console::pick::get_key() {
    return getch();
}
