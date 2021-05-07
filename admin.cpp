//
// Created by pc on 07.05.2021.
//

#include "windows_console_tools/win_colors.h"
#include "board.h"

coord cursor_position = {0, 0};

board game(10, 10);

#include <conio.h>

void admin_view(board &game);

void analyze_command();

void analyze_movement(char key);


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
        admin_view(game);

        key = getch();
        if (key == '\\') void analyze_command();
        else analyze_movement(key);

    }
}


void admin_view(board &game) {

    for (int i = 0; i < game.getH(); i++) {
        for (int j = 0; j < game.getW(); j++) {
            color text_color = game.get_cell(i, j).get_unicode().icon_color;
            color background_color = black;

            if (cursor_position == coord(i, j))
                background_color = light_aqua;
            std::wcout << cc(text_color, background_color) << game.get_cell(i, j).get_unicode().image;


        }
        std::wcout << "\n";
    }
    std::wcout << "\n\n";
}

void analyze_command() {
    // todo color the correct syntax

    std::cout << cc(yellow, black) << "\n> " << cc(light_yellow);
    std::string current_command;
    std::cin >> current_command;
    if (current_command == "add" ||
        current_command == "a") {

    }
    if (current_command == "del" ||
        current_command == "d") {
        game.get_cell(cursor_position) = empty_cell(true);


    }
    if (current_command == "help") {


    }
    if (current_command == "clear") {
        for (int i = 0; i < game.getH(); i++) {
            for (int j = 0; j < game.getW(); j++) {
                game.get_cell(i, j) = empty_cell(true);

            }
        }

    }
    if (current_command == "rotate" ||
        current_command == "r") {
        if (game.get_cell(cursor_position) == t_move) {
            auto dir = ((move_cell *) &game.get_cell(cursor_position))->getMoveDirection();
            switch (dir) {
                case left:
                    ((move_cell *) &game.get_cell(cursor_position))->setMoveDirection(up);
                    break;
                case right:
                    ((move_cell *) &game.get_cell(cursor_position))->setMoveDirection(down);
                    break;
                case down:
                    ((move_cell *) &game.get_cell(cursor_position))->setMoveDirection(left);
                    break;
                case up:
                    ((move_cell *) &game.get_cell(cursor_position))->setMoveDirection(right);
                    break;

            }

        }
        else if (game.get_cell(cursor_position) == t_spawn) {
            auto dir = ((spawn_cell *) &game.get_cell(cursor_position))->getSpawnDirection();
            switch (dir) {
                case left:
                    ((spawn_cell *) &game.get_cell(cursor_position))->setSpawnDirection(up);
                    break;
                case right:
                    ((spawn_cell *) &game.get_cell(cursor_position))->setSpawnDirection(down);
                    break;
                case down:
                    ((spawn_cell *) &game.get_cell(cursor_position))->setSpawnDirection(left);
                    break;
                case up:
                    ((spawn_cell *) &game.get_cell(cursor_position))->setSpawnDirection(right);
                    break;
            }

        }
        else if (game.get_cell(cursor_position) == t_turn){
            auto dir = ((turn_cell *) &game.get_cell(cursor_position))->getTurnDirection();
            switch (dir) {
                case left:
                    ((turn_cell *) &game.get_cell(cursor_position))->setTurnDirection(up);
                    break;
                case right:
                    ((turn_cell *) &game.get_cell(cursor_position))->setTurnDirection(down);
                    break;
                case down:
                    ((turn_cell *) &game.get_cell(cursor_position))->setTurnDirection(left);
                    break;
                case up:
                    ((turn_cell *) &game.get_cell(cursor_position))->setTurnDirection(right);
                    break;
            }

        }

    }

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

    }
    if (cursor_position.y >= game.getW()) cursor_position.y = 0;
    if (cursor_position.x >= game.getH()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = game.getW() - 1;
    if (cursor_position.x < 0) cursor_position.x = game.getH() - 1;

}

