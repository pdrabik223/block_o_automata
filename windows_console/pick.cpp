//
// Created by studio25 on 20.05.2021.
//

#include "pick.h"

void win_console::pick::display_ui() {

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

unsigned char win_console::pick::get_key() {
    return getch();
}
