//
// Created by pc on 04.05.2021.
//

/// the first approach


#include "windows_console_tools/win_colors.h"
#include "board.h"

/// the plan

/// todo make special class for displaying stuff
/// todo create whole game sequence:
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::seconds(x))

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
    /// allow using chart in console
    _setmode(_fileno(stdout), _O_U16TEXT);


    std::wcout << cc(gray) << "barrier_cell\t" << (wchar_t) (9635) << " \n";
    std::wcout << cc(gray) << "movable_barrier_cell\t" << (wchar_t) (9634) << " \n";
    std::wcout << cc(red) << "kill_cell\t" << (wchar_t) 10006 << " \n";


    std::wcout << cc(yellow) << "move_cell\t" << (wchar_t) 11166 << " \n\t\t" << (wchar_t) 11164 << " \n\t\t"
               << (wchar_t) 11165 << " \n\t\t" << (wchar_t) 11167 << std::endl;

    std::wcout << cc(green) << "spawn_cell\t" << (wchar_t) 11166 << " \n\t\t" << (wchar_t) 11164 << " \n\t\t"
               << (wchar_t) 11165 << " \n\t\t" << (wchar_t) 11167 << std::endl;

    std::wcout << cc(blue) << "turn_cell\t" << (wchar_t) 11166 << " \n\t\t" << (wchar_t) 11164 << " \n\t\t"
               << (wchar_t) 11165 << " \n\t\t" << (wchar_t) 11167 << std::endl;

    wchar_t goal = 11044;
    std::wcout << cc(purple) << "goal_cell\t" << goal << L" \n";


    level_info level{10, 10}
    (0, 0);


    for (int i = 0; i < level.size(); i++) {

        if (i % level.getWidth() == 0 ||
            i / level.getWidth() == 0 ||
            i / level.getWidth() == (level.getHeight() - 1) ||
            i % level.getWidth() == (level.getWidth() - 1))
            level[i] = new barrier_cell(false);

        else level[i] = new empty_cell(true);
    }

    level[{3, 6}] = new goal_cell();
    level[{3, 5}] = new kill_cell();


    level[{5, 8}] = new turn_cell(down);

    level[{0, 7}] = new barrier_cell(true);
    level[{1, 7}] = new spawn_cell(down);

    level[{1, 1}] = new turn_cell(right);

    level[{1, level.getWidth() - 4}] = new turn_cell(down);
    level[{level.getHeight() - 2, level.getWidth() - 2}] = new turn_cell(left);
    level[{level.getHeight() - 2, 1}] = new turn_cell(up);


    level[{2, 2}] = new kill_cell();
    level[{2, 3}] = new kill_cell();
    level[{2, 4}] = new kill_cell();

    level[{6, 2}] = new kill_cell();
    level[{6, 3}] = new kill_cell();
    level[{6, 4}] = new kill_cell();


    for (unsigned i = 2; i < 5; ++i) {
        level[{3, i}] = new empty_cell(false);
        level[{4, i}] = new empty_cell(false);
        level[{5, i}] = new empty_cell(false);
    }

    level[{5, 4}] = new move_cell(right);


    board first(level);

    char k;
    int frame_counter = 0;

    while (2 > 1) {
        for (unsigned h = 0; h < level.getHeight(); h++) {
            for (unsigned w = 0; w < level.getWidth(); w++) {

                color text_color = first.get_cell_icon({h, w}).text_color;
                color background_color = black;
                first.get_cell_icon({h, w});
                std::wcout << cc(text_color, background_color) << first.get_cell_icon({h, w}).image<<" ";

            }
            std::wcout << "\n";
        }

        std::wcout << "\n\n";
        first.iterate();
        std::wcout << cc(yellow, black) << "frame counter :" << cc(red) << frame_counter << std::endl;
        ++frame_counter;
        WAIT(2);
    }

    return 0;
}

#pragma clang diagnostic pop