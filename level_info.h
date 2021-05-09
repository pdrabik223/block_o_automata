//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_INFO_H
#define BLOCK_O_AUTOMATA_LEVEL_INFO_H

// todo figure out if we should move all level creation stuff to this class and in board use level as level
//
#include "cells_dir/empty_cell.h"


#include <fstream>

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>
#include <vector>


/// \return current date in form of a string
std::string current_date();

enum game_goal {

    collect_all_goals,
    kill_all_enemies

};
enum difficulty {
    not_specified,
    easy,
    medium,
    hard,
    insane


};
// todo
//  save on disk in binary form
//  strong and safe copy constructor



class level_info {
public:
    /// \brief used to get level-identifying info
    /// \return string containing basic info about level
    std::wstring get_info();

    /// \brief constructor is simple
    ///  all of the fields will be accessed by set adn get functions
    level_info(unsigned int width, unsigned int height);

    /// \brief no param constructor
    ///     level will be as default as it gets
    level_info();

    /// \return resizes field without losing data
    void resize(unsigned int new_width, unsigned int new_height);


    void save();
    void load(std::string path);


    /// a lot of setters

    void setLevelName(const std::string &levelName);

    void setAuthor(const std::string &author);

    void setLevelDifficulty(difficulty levelDifficulty);

    void setLevelBeaten(bool levelBeaten);

    void setMaxIteration(unsigned int maxIteration);

    void setMaxIterationBeaten(bool maxIterationBeaten);

    void setMaxPieceCost(unsigned int maxPieceCost);

    void setMaxPieceCostBeaten(bool maxPieceCostBeaten);

    void setGoalOfTheLevel(game_goal goalOfTheLevel);

    void setNumberOfPawns(const std::vector<int> &numberOfPawns);


    /// this class requires a lot of set and get functions
    /// we wanna make sure that this data want be changed
    unsigned int getWidth() const;

    unsigned int getHeight() const;

    const std::string &getLevelName() const;

    const std::string &getAuthor() const;

    difficulty getLevelDifficulty() const;

    bool isLevelBeaten() const;

    unsigned int getMaxIteration() const;

    bool isMaxIterationBeaten() const;

    unsigned int getMaxPieceCost() const;

    bool isMaxPieceCostBeaten() const;

    game_goal getGoalOfTheLevel() const;

protected:

    unsigned width;
    unsigned height;
    std::string level_name;
    std::string author;
    difficulty level_difficulty;
    bool level_beaten;

    unsigned max_iteration;
    bool max_iteration_beaten;

    unsigned max_piece_cost;
    bool max_piece_cost_beaten;
    game_goal goal_of_the_level;

    std::array<int, 5> number_of_pawns;
    std::vector<cell *> level;


};

string

        std::string

current_date() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

std::wstring level_info::get_info() {
    std::wstring line = level_name + " by " + author;
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
    return line;
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

void level_info::setNumberOfPawns(const std::vector<int> &numberOfPawns) {
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
        level.push_back(empty_cell(true));

}

void level_info::resize(unsigned int new_width, unsigned int new_height) {
    std::vector<cell *> level_copy = level;
    unsigned level_copy_elem = 0;
    level.clear();

    for (int x = 0; x < new_height; x++) {
        for (int y = 0; y < new_width; y++) {
            if (x < width && y < height) {

                level.push_back(level_copy[i]);
                ++level_copy_elem
            }
            level.push_back(empty_cell(true));

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
        level.push_back(empty_cell(false));

}

void level_info::save() {
    ofstream myfile;
    std::string file_path =level_name+".txt";
    myfile.open (file_path);
    myfile << "boa1\n"; // to identify correct file
    myfile<<level_name<<"\n"; // every field is separated by new line
    myfile<<author<<"\n";
    myfile<<level_difficulty<<"\n";
    myfile<<level_beaten<<"\n";

    myfile<<max_iteration<<"\n";
    myfile<<max_iteration_beaten<<"\n";

    myfile<<max_piece_cost<<"\n";
    myfile<<max_piece_cost_beaten<<"\n";

    myfile<<goal_of_the_level<<"\n";

    for(int i=0;i<number_of_pawns.size())
        myfile<<number_of_pawns[i]<<" ";
    myfile<<"\n";
    myfile<<width<<"\n"
    myfile<<height<<"\n"

    for(int i=0;i<number_of_pawns.size())
        myfile<<level[i]<<" ";

    myfile.close();
}


#endif //BLOCK_O_AUTOMATA_LEVEL_INFO_H
