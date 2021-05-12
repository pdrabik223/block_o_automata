//
// Created by pc on 07.05.2021.
//

#include "windows_console_tools/win_colors.h"
#include "board.h"

coord cursor_position = {0, 0};

level_info level{10,10};
board game(level);
bool close_admin = false;

#define ERROR(x) std::wcout << cc(red, black) << "\n error, "<<x<< cc(white, black)<<std::endl

#include <conio.h>

void controlled_view(level_info &level);

void analyze_command();

void analyze_movement(char key);

void cell_picker();

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    //actions :
    // add
    //  goal
    //  barier
    //      movable
    //      not
    // del
    // help
    // rotate
    // reload
    // clear
    // barier

    char key;
    while (2 > 1) {
        system("cls");
        controlled_view(level);

        key = getch();
        if (key == '-') analyze_command();
        else analyze_movement(key);
        if(close_admin) return 1;
    }
    return 0;
}


void controlled_view(level_info &level) {

    for (int i = 0; i < level.getHeight(); i++) {
        for (int j = 0; j < level.getWidth(); j++) {
            color text_color = level.get_cell(i, j).get_unicode().icon_color;
            color background_color = black;

            if (cursor_position == coord(i, j))
                background_color = light_aqua;
            std::wcout << cc(text_color, background_color) << level.get_cell(i, j).get_unicode().image;


        }
        std::wcout << "\n";
    }
    std::wcout << "\n\n";
}

void analyze_command() {
    // todo color the correct syntax

    std::wcout << cc(yellow, black) << "\n> " << cc(light_yellow);
    std::string current_command;
    std::cin >> current_command;
    std::wcout << "\n";
    if (current_command == "add" ||
        current_command == "a") {
        cell_picker();

    } else if (current_command == "del" ||
               current_command == "d") {

        level.set_cell(cursor_position, new empty_cell(true));


    } else if (current_command == "help") {
        std::wcout << "here comes help\n";
        std::wcout << cc(blue, red) << "here it comes\n";
        std::wcout << cc(red, light_blue) << "and here it id\n";

    } else if (current_command == "clear") {
        for (unsigned i = 0; i < level.getHeight(); i++) {
            for (unsigned j = 0; j < level.getWidth(); j++) {
                level.set_cell({i, j}, new empty_cell(true));

            }
        }

    } else if (current_command == "rotate" ||
               current_command == "r") {
        if (level.get_cell(cursor_position) == t_move) {

            auto dir = ((move_cell *) &level.get_cell(cursor_position))->getMoveDirection();

            switch (dir) {
                case left:
                    ((move_cell *) &level.get_cell(cursor_position))->setMoveDirection(up);
                    break;
                case right:
                    ((move_cell *) &level.get_cell(cursor_position))->setMoveDirection(down);
                    break;
                case down:
                    ((move_cell *) &level.get_cell(cursor_position))->setMoveDirection(left);
                    break;
                case up:
                    ((move_cell *) &level.get_cell(cursor_position))->setMoveDirection(right);
                    break;

            }

        } else if (level.get_cell(cursor_position) == t_spawn) {
            auto dir = ((spawn_cell *) &level.get_cell(cursor_position))->getSpawnDirection();
            switch (dir) {
                case left:
                    ((spawn_cell *) &level.get_cell(cursor_position))->setSpawnDirection(up);
                    break;
                case right:
                    ((spawn_cell *) &level.get_cell(cursor_position))->setSpawnDirection(down);
                    break;
                case down:
                    ((spawn_cell *) &level.get_cell(cursor_position))->setSpawnDirection(left);
                    break;
                case up:
                    ((spawn_cell *) &level.get_cell(cursor_position))->setSpawnDirection(right);
                    break;
            }

        } else if (level.get_cell(cursor_position) == t_turn) {
            auto dir = ((turn_cell *) &level.get_cell(cursor_position))->getTurnDirection();
            switch (dir) {
                case left:
                    ((turn_cell *) &level.get_cell(cursor_position))->setTurnDirection(up);
                    break;
                case right:
                    ((turn_cell *) &level.get_cell(cursor_position))->setTurnDirection(down);
                    break;
                case down:
                    ((turn_cell *) &level.get_cell(cursor_position))->setTurnDirection(left);
                    break;
                case up:
                    ((turn_cell *) &level.get_cell(cursor_position))->setTurnDirection(right);
                    break;
            }

        }

    }
    else if(current_command == "quit"||
            current_command == "q"  ) {
                    close_admin = true;

    }else
        ERROR("unknown command");

}


void analyze_movement(char key) {
    switch (key) {
        case 'a':
            cursor_position.y--;
            break;
        case 'w':
            cursor_position.x--;
            break;
        case 's':
            cursor_position.x++;
            break;
        case 'd':
            cursor_position.y++;
            break;
        case 32:
            game.iterate();
            break;
        default:
            ERROR("unknown key");
            break;

    }
    if (cursor_position.y >= level.getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= level.getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = level.getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = level.getHeight() - 1;

}

void cell_picker() {
    std::string current_command;
    std::wcout << cc(yellow, black) << "cell type> " << cc(light_yellow);
    std::cin >> current_command;


    if (current_command == "barrier" ||
        current_command == "b") {

        std::wcout << cc(yellow, black) << "movable> " << cc(light_yellow);
        std::cin >> current_command;

        if (current_command == "y" ||
            current_command == "t" ||
            current_command == "yes" ||
            current_command == "true") {

            level.set_cell(cursor_position, new barrier_cell(true));


        } else if (current_command == "n" ||
                   current_command == "f" ||
                   current_command == "no" ||
                   current_command == "false") {

            level.set_cell(cursor_position, new barrier_cell(false));

        } else
            ERROR("unknown argument");


    } else if (current_command == "goal" ||
               current_command == "g") {

        level.set_cell(cursor_position, new goal_cell());


    } else if (current_command == "kill" ||
               current_command == "k") {


        int kills;
        std::wcout << cc(yellow, black) << "kills> " << cc(light_yellow);
        std::cin >> kills;

        level.set_cell(cursor_position, new kill_cell(kills));


    } else if (current_command == "move" ||
               current_command == "m") {


        std::wcout << cc(yellow, black) << "direction> " << cc(light_yellow);
        std::cin >> current_command;

        direction dir;
        if (current_command == "l" || current_command == "left")
            dir = left;
        else if (current_command == "r" || current_command == "right")
            dir = right;
        else if (current_command == "u" || current_command == "up")
            dir = up;
        else if (current_command == "d" || current_command == "down")
            dir = down;
        else
            ERROR("unknown argument");


        level.set_cell(cursor_position, new move_cell(dir));

    } else if (current_command == "spawn" ||
               current_command == "s") {


        std::wcout << cc(yellow, black) << "direction> " << cc(light_yellow);
        std::cin >> current_command;

        direction dir;

        if (current_command == "l" || current_command == "left")
            dir = left;
        else if (current_command == "r" || current_command == "right")
            dir = right;
        else if (current_command == "u" || current_command == "up")
            dir = up;
        else if (current_command == "d" || current_command == "down")
            dir = down;
        else
            ERROR("unknown argument");

        level.set_cell(cursor_position, new spawn_cell(dir));

    } else if (current_command == "turn" ||
               current_command == "t") {
        std::wcout << cc(yellow, black) << "direction> " << cc(light_yellow);
        std::cin >> current_command;

        direction dir;

        if (current_command == "l" || current_command == "left")
            dir = left;
        else if (current_command == "r" || current_command == "right")
            dir = right;
        else if (current_command == "u" || current_command == "up")
            dir = up;
        else if (current_command == "d" || current_command == "down")
            dir = down;
        else
            ERROR("unknown argument");


        level.set_cell(cursor_position, new turn_cell(dir));
    } else
        ERROR("unknown command");
}
