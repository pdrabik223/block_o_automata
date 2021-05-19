//
// Created by pc on 13.05.2021.
//

#include "level_edit.h"

using namespace le;

void level_edit::controlled_view() {

    for (int i = 0; i <= getHeight()+1; i++) {

        if(i < getHeight()) {
            for (int j = 0; j < getWidth(); j++) {

                color text_color = get_cell(i, j).get_unicode().icon_color;
                color background_color = black;

                if (cursor_position == coord(i, j))
                    background_color = light_aqua;
                std::wcout << cc(text_color, background_color) << get_cell(i, j).get_unicode().image;

            }
        }else {
            color text_color = yellow;
            color background_color = black;
            {
                if (cursor_position.y == getWidth()) background_color = light_aqua;

                if (i % getHeight() == getHeight() / 2) std::wcout << cc(text_color, background_color) << "-";
                else std::wcout << cc(text_color, background_color) << " ";
            }
            {
                if (cursor_position.y == getWidth() + 1) background_color = light_aqua;

                if (i % getHeight() == getHeight() / 2) std::wcout << cc(text_color, background_color) << "+";
                else std::wcout << cc(text_color, background_color) << "  ";


            }
        }

        std::wcout <<cc(white,black)<< "\n";
    }

    for (unsigned i = 0; i < all_blocks.size(); i++) {

        color text_color = yellow;
        color background_color = black;
        if (cursor_position.y == getWidth()) background_color = light_aqua;

        if (i % getWidth() == getWidth() / 2) std::wcout << cc(text_color, background_color) << "-\n";
        else std::wcout << cc(text_color, background_color) << "  ";

    }

    for (unsigned i = 0; i < all_blocks.size(); i++) {

        color text_color = yellow;
        color background_color = black;
        if (cursor_position.y == getWidth()) background_color = light_aqua;

        if (i % getWidth() == getWidth() / 2) std::wcout << cc(text_color, background_color) << "+\n";
        else std::wcout << cc(text_color, background_color) << "  ";

    }


    for (unsigned i = 0; i < all_blocks.size(); i++) {
        if (i == current_block)std::wcout << cc(all_blocks[i]->get_unicode().icon_color, light_yellow);
        else std::wcout << cc(all_blocks[i]->get_unicode().icon_color, black);
        std::wcout << "  " << all_blocks[i]->get_unicode().image;
        std::wcout << cc(white, black);
    }


    std::wcout << "\n";
}


player_action level_edit::analyze_movement(char key) {
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
            return run_simulation;
        case 'q':
            return quit_edit;
        case 'i':
            return set_info;
        case 13:
            // set pawn in place
            copy_cell(cursor_position, all_blocks[current_block]);
            break;
        case 'r':

            level[cursor_position.toUint(getWidth())]->rotateRight();

            break;
        case 't':
            if (get_cell(cursor_position) == Barrier) {
                auto dir = ((barrier_cell *) &get_cell(cursor_position));
                dir->setMovable(!dir->isMovable());
            } else if (get_cell(cursor_position) == Empty) {
                auto dir = ((empty_cell *) &get_cell(cursor_position));
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
    if (cursor_position.y >= getWidth()) cursor_position.y = 0;
    if (cursor_position.x >= getHeight()) cursor_position.x = 0;

    if (cursor_position.y < 0) cursor_position.y = getWidth() - 1;
    if (cursor_position.x < 0) cursor_position.x = getHeight() - 1;
    return nothing;
}

int level_edit::run_sim() {

    board game(*this);
    while (2 > 1) {

        game.iterate();
       // if (!game.goal_cells_left()) return 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
        game.show_level_win_console();

    }

}

void level_edit::set_additional_info() {

    std::wcout << "\nlevel name :";
    std::cin >> level_name;

    std::wcout << "\nauthor :";
    std::cin >> author;

    std::wcout << "\nset level difficulty 1-4 : ";
    int temp;
    std::cin >> temp;

    if (temp >= 4) temp = 3;
    if (temp < 0) temp = 0;

    level_difficulty = (difficulty) temp;

    std::wcout << "\nmax iterations  :";
    std::cin >> temp;

    if (temp >= 999) temp = 999;
    if (temp < 0) temp = 0;
    max_iteration = temp;

    std::wcout << "\nmax piece cost  :";
    std::cin >> temp;

    if (temp >= 999) temp = 999;
    if (temp < 0) temp = 0;
    max_piece_cost = temp;

    std::wcout << "\n max number of pawns that user has at his disposal :\n";
    for (int i = 0; i < number_of_pawns.size(); i++) {
        std::wcout << "max piece cost  :";
        std::cin >> temp;

        if (temp >= 999) temp = 999;
        if (temp < 0) temp = 0;

        number_of_pawns[i] = temp;
    }
    std::wcout << "changes saved";

}


void level_edit::main_loop() {
    system("cls");

    std::cout << "welcome to level_editor\n";

    _setmode(_fileno(stdout), _O_U16TEXT);

    char key_pressed = 0;
    player_action operation;

    while (2 > 1) {
        system("cls");

        controlled_view();

        key_pressed = getch();

        operation = analyze_movement(key_pressed);

        if (operation == quit_edit) break;
        if (operation == run_simulation) run_sim();
        if (operation == set_info) set_additional_info();

    }

    save();
}
