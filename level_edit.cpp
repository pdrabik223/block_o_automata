//
// Created by pc on 13.05.2021.
//

#include "level_edit.h"

void level_edit::controlled_view() {

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


player_choice level_edit::analyze_movement(char key) {
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
            level.copy_cell(cursor_position, all_blocks[current_block]);
            break;
        case 'r':

            level[cursor_position]->rotateRight();

            break;
        case 't':
            if (level.get_cell(cursor_position) == Barrier) {
                auto dir = ((barrier_cell *) &level.get_cell(cursor_position));
                dir->setMovable(!dir->isMovable());
            } else if (level.get_cell(cursor_position) == Empty) {
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
    return nothing;
}

int level_edit::run_sim() {

    board game(level);
    while (2 > 1) {

        game.iterate();
        if (!game.goal_cells_left()) return 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
        game.show_level_win_console();

    }

}

void level_edit::set_additional_info() {

    std::cout << "\nlevel name :";
    std::cin >> level.level_name;

    std::cout << "\nauthor :";
    std::cin >> level.author;

    std::cout << "\nset level difficulty 1-4 : ";
    int temp;
    std::cin >> temp;

    if (temp >= 4) temp = 3;
    if (temp < 0) temp = 0;

    level.level_difficulty = (difficulty) temp;

    std::cout << "\nmax iterations  :";
    std::cin >> temp;

    if (temp >= 999) temp = 999;
    if (temp < 0) temp = 0;
    level.max_iteration = temp;

    std::cout << "\nmax piece cost  :";
    std::cin >> temp;

    if (temp >= 999) temp = 999;
    if (temp < 0) temp = 0;
    level.max_piece_cost = temp;

    std::cout << "\n max number of pawns that user has at his disposal :";
    for (int i = 0; i < level.number_of_pawns.size(); i++) {
        std::cout << "\nmax piece cost  :";
        std::cin >> temp;

        if (temp >= 999) temp = 999;
        if (temp < 0) temp = 0;

        level.number_of_pawns[i] = temp;
    }
    std::cout << "changes saved";

}


void level_edit::main_loop() {
    std::cout << "welcome to level_editor\n";
//    std::cout << "specify size of your level: \n";
//    std::cout << "height: ";
//    unsigned height;
//    std::cin >> height;
//    std::cout << "width: ";
//    unsigned width;
//    std::cin >> width;

//    level.resize(height, width);

    _setmode(_fileno(stdout), _O_U16TEXT);

    char key_pressed = 0;
    player_choice operation;

    while (2 > 1) {
        system("cls");

        controlled_view();

        key_pressed = getch();

        operation = analyze_movement(key_pressed);
        if (operation == quit_edit) break;
        if (operation == run_simulation) run_sim();
        if (operation == set_info) set_additional_info();
    }

    level.save();
}
