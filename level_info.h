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
#include <array>

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

    void load(const std::string& path);


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

    void setNumberOfPawns(const std::array<int, 5> &numberOfPawns);


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

#endif //BLOCK_O_AUTOMATA_LEVEL_INFO_H
