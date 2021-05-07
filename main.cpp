//
// Created by pc on 04.05.2021.
//

/// the first approach


#include "windows_console_tools/win_colors.h"
#include "board.h"

/// the plan
/// todo requ move move
/// todo testing place <- it's like this admin file
/// todo make special class for displaying stuff
/// todo create whole game sequence:
/// - info screen
/// - chose level screen
/// - play level screen
/// - get input
/// -main game loop
/// - update best time and best blocks cost
/// - level creator
/// - save level in place
/// - info about challenges and stuff
#include <thread>
#include <chrono>

#define WAIT(x) std::this_thread::sleep_for(std::chrono::seconds(x))

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
    /// allow using chart in console
    _setmode(_fileno(stdout), _O_U16TEXT);


    std::wcout << cc(gray) << "barrier_cell\t" << L"\x25A3\n";
    std::wcout << cc(gray) << "movable_barrier_cell\t" << L"\x25A2\n";
    std::wcout << cc(red) << "kill_cell\t" << L"\x2716\n";

    std::wcout << cc(yellow) << "move_cell\t" << L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";

    std::wcout << cc(green) << "spawn_cell\t" << L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";

    std::wcout << cc(blue) << "turn_cell\t" << L"\x2B9E\n\t\t\x2B9C \n\t\t\x2B9D \n\t\t\x2B9f\n";


    std::wcout << cc(purple, red) << "goal_cell\t" << L"\x2B24 \n";


    board first(10, 10);
    char k;
    int frame_counter = 0;
    while (2 > 1) {
        first.show_level_win_console();
        first.iterate();
        std::wcout << cc(yellow, black) << "frame counter :" << cc(red) << frame_counter << std::endl;
        ++frame_counter;
        WAIT(2);
    }

    return 0;
}

#pragma clang diagnostic pop