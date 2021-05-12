//
// Created by pc on 12.05.2021.
//

#include <iostream>
#include <conio.h>
#include <thread>
#include "board.h"
#include "level_info.h"

#define ERROR(x) std::wcout << cc(red, black) << "\n error, "<<x<< cc(white, black)<<std::endl

void controlled_view(level_info &level);

coord cursor_position = {0, 0};
std::array<cell *, 6> all_blocks = {new barrier_cell(),
                                    new move_cell(),
                                    new kill_cell(),
                                    new turn_cell(),
                                    new spawn_cell(),
                                    new goal_cell()};

int analyze_movement(char key, level_info &level);

int current_block = 0;

int run_sim(level_info level);

int main() {

    std::cout << "welcome to level_editor\n";
    std::cout << "specify size of your level: \n";
    std::cout << "height: ";
    unsigned height;
    std::cin >> height;
    std::cout << "  width: ";
    unsigned width;
    std::cin >> width;
    level_info level(height, width);

    char key;
    int key_flag;
    _setmode(_fileno(stdout), _O_U16TEXT);
    while (2 > 1) {
        system("cls");
        controlled_view(level);

        key = getch();
        //     if (key == '-') analyze_command();

        key_flag = analyze_movement(key, level);
        if (key_flag == 1) break;
        if (key_flag == 2) run_sim(level);

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
    for (unsigned i = 0; i < all_blocks.size(); i++) {
        if (i == current_block)std::wcout << cc(all_blocks[i]->get_unicode().icon_color, light_yellow);
        else std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);
        std::wcout << "  " << all_blocks[i]->get_unicode().image;
        std::wcout << cc(white, black);
    }
    std::wcout << "\n";
}


int analyze_movement(char key, level_info &level) {
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
            return 2;
        case 'q':
            return 1;
        case 13:
            // set pawn in place
            level.copy_cell(cursor_position, all_blocks[current_block]);
            break;
        case 'r':
            // todo rotate right
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

            break;
        case 't':
            if (level.get_cell(cursor_position) == t_barrier) {
                auto dir = ((barrier_cell *) &level.get_cell(cursor_position));
                dir->setMovable(!dir->isMovable());
            } else if (level.get_cell(cursor_position) == t_empty) {
                auto dir = ((empty_cell *) &level.get_cell(cursor_position));
                dir->setLocked(!dir->isLocked());
            }
            break;

        case '1':
            current_block = 0;
            break;
        case '2':
            current_block = 1;
            break;
        case '3':
            current_block = 2;
            break;
        case '4':
            current_block = 3;
            break;
        case '5':
            current_block = 4;
            break;
        case '6':
            current_block = 5;
            break;


        default:
            ERROR("unknown key");
            break;


    }
    if (cursor_position.y >= level.getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= level.getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = level.getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = level.getHeight() - 1;
    return 0;
}

int run_sim(level_info level) {

    board game(level);
    while (2 > 1) {
        game.iterate();
        if (!game.goal_cells_left()) return 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
        game.show_level_win_console();

    }

}