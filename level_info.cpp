//
// Created by pc on 11.05.2021.
//

#include "level_info.h"
#include "cells_dir/barrier_cell.h"
#include "cells_dir/move_cell.h"
#include "cells_dir/kill_cell.h"
#include "cells_dir/spawn_cell.h"
#include "cells_dir/turn_cell.h"
#include "cells_dir/goal_cell.h"


std::string current_date() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

std::wstring level_info::get_info() {
    std::string line;
    line += level_name;
    line += " by ";
    line += author;
    if (level_beaten) {
        line += " B ";
    } else line += "   ";

    if (max_iteration_beaten) {
        line += " I ";
    } else line += "   ";

    if (max_piece_cost_beaten) {
        line += " C ";
    } else line += "   ";
    line += "\n";

    std::wstring wline;
    for (auto i:line)
        wline.push_back((wchar_t) i);

    return wline;
}

unsigned int level_info::getWidth() const {
    return width;
}

unsigned int level_info::getHeight() const {
    return height;
}

const std::string &level_info::getLevelName() const {
    return level_name;
}

const std::string &level_info::getAuthor() const {
    return author;
}

difficulty level_info::getLevelDifficulty() const {
    return level_difficulty;
}

bool level_info::isLevelBeaten() const {
    return level_beaten;
}

unsigned int level_info::getMaxIteration() const {
    return max_iteration;
}

bool level_info::isMaxIterationBeaten() const {
    return max_iteration_beaten;
}

unsigned int level_info::getMaxPieceCost() const {
    return max_piece_cost;
}

bool level_info::isMaxPieceCostBeaten() const {
    return max_piece_cost_beaten;
}

game_goal level_info::getGoalOfTheLevel() const {
    return goal_of_the_level;
}

void level_info::setLevelName(const std::string &levelName) {
    level_name = levelName;
}

void level_info::setAuthor(const std::string &author) {
    level_info::author = author;
}

void level_info::setLevelDifficulty(difficulty levelDifficulty) {
    level_difficulty = levelDifficulty;
}

void level_info::setLevelBeaten(bool levelBeaten) {
    level_beaten = levelBeaten;
}

void level_info::setMaxIteration(unsigned int maxIteration) {
    max_iteration = maxIteration;
}

void level_info::setMaxIterationBeaten(bool maxIterationBeaten) {
    max_iteration_beaten = maxIterationBeaten;
}

void level_info::setMaxPieceCost(unsigned int maxPieceCost) {
    max_piece_cost = maxPieceCost;
}

void level_info::setMaxPieceCostBeaten(bool maxPieceCostBeaten) {
    max_piece_cost_beaten = maxPieceCostBeaten;
}

void level_info::setGoalOfTheLevel(game_goal goalOfTheLevel) {
    goal_of_the_level = goalOfTheLevel;
}

void level_info::setNumberOfPawns(const std::array<int, 5> &numberOfPawns) {
    number_of_pawns = numberOfPawns;
}

level_info::level_info(unsigned int width, unsigned int height) : width(width), height(height) {


    level_name = current_date();
    author = "noname";
    level_difficulty = not_specified;
    level_beaten = false;

    max_iteration = 0;
    max_iteration_beaten = 0;

    max_piece_cost = 0;
    max_piece_cost_beaten = 0;

    goal_of_the_level = collect_all_goals;

    number_of_pawns = {999, 999, 999, 999, 999};

    for (int i = 0; i < width * height; i++)
        level.push_back(new empty_cell(true));

}

void level_info::resize(unsigned int new_width, unsigned int new_height) {
    std::vector<cell *> level_copy = level;
    unsigned level_copy_elem = 0;
    level.clear();

    for (int x = 0; x < new_height; x++) {
        for (int y = 0; y < new_width; y++) {
            if (x < width && y < height) {

                level.push_back(level_copy[level_copy_elem]);
                ++level_copy_elem;
            }
            level.push_back(new empty_cell(true));

        }
    }
    width = new_width;
    height = new_height;
}

level_info::level_info() {

    level_name = current_date();
    author = "noname";
    level_difficulty = not_specified;
    level_beaten = false;

    max_iteration = 0;
    max_iteration_beaten = 0;

    max_piece_cost = 0;
    max_piece_cost_beaten = 0;

    goal_of_the_level = collect_all_goals;

    number_of_pawns = {999, 999, 999, 999, 999};

    width = 1;
    height = 1;
    for (int i = 0; i < width * height; i++)
        level.push_back(new empty_cell(false));

}

void level_info::save() {

    std::ofstream myfile;
    std::string date = level_name.erase(0, 11);
    for (char &i:date)
        if (i == ':') i = '_';

    std::cout << date;
    std::string file_path = "C:\\Users\\pc\\Documents\\block_o_automata\\levels\\" + date + ".txt";


    myfile.open(file_path);
    if (!myfile.is_open()) std::cout << "\nfile is fucked ";

//    myfile << "boa1\n"; // to identify correct file
    myfile << level_name << "\n"; // every field is separated by new line
    myfile << author << "\n";
    myfile << level_difficulty << "\n";
    myfile << level_beaten << "\n";

    myfile << max_iteration << "\n";
    myfile << max_iteration_beaten << "\n";

    myfile << max_piece_cost << "\n";
    myfile << max_piece_cost_beaten << "\n";

    myfile << goal_of_the_level << "\n";

    for (int number_of_pawn : number_of_pawns)
        myfile << number_of_pawn << " ";

    myfile << "\n";
    myfile << width << "\n";
    myfile << height << "\n";

    for (auto &i : level) {
        myfile << i << " ";

    }
    myfile.close();
}

void level_info::load(const std::string &path) {
    std::ifstream myfile;
    myfile.open(path);
    std::string file_header;
    if (!myfile.is_open()) std::cout << "\nfile is fucked ";
    // myfile>>file_header;
//    if(file_header != "boa1"){
//        myfile.close();
//        delete this;
//        return;
//    }
    myfile >> level_name; // every field is separated by new line
    myfile >> author;
    int temp_int;
    myfile >> temp_int;
    level_difficulty = (difficulty) temp_int;
    myfile >> level_beaten;

    myfile >> max_iteration;
    myfile >> max_iteration_beaten;

    myfile >> max_piece_cost;
    myfile >> max_piece_cost_beaten;

    myfile >> temp_int;
    goal_of_the_level = (game_goal) temp_int;

    for (int &number : number_of_pawns)
        myfile >> number;

    myfile >> width;
    myfile >> height;


    type cell_type;
    for (int i = 0; i < width * height; i++) {

        myfile >> temp_int;
        cell_type = (type) temp_int;
        switch (cell_type) {
            case t_barrier:
                level.push_back(new barrier_cell());
                break;
            case t_move:
                level.push_back(new move_cell());
                break;
            case t_kill:
                level.push_back(new kill_cell());
                break;
            case t_spawn:
                level.push_back(new spawn_cell());
                break;
            case t_turn:
                level.push_back(new turn_cell());

                break;
            case t_cell:
                assert(false);
                /// here comes exception

                break;
            case t_empty:
                level.push_back(new empty_cell());

                break;
            case t_goal:
                level.push_back(new goal_cell());
                break;
            default:
                assert(false);
                /// here comes exception
        }
        myfile >> *level.back();

    }


    myfile.close();
}

