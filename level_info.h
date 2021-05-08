//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_INFO_H
#define BLOCK_O_AUTOMATA_LEVEL_INFO_H

// todo figure out if we should move all level creation stuff to this class and in board use level as level
//


#include <string>

enum game_goal{

    collect_all_goals,
    kill_all_enemies

};
enum difficulty{
    easy,
    medium,
    hard,
    insane


};
// todo
//  save on disk in binary form
//  strong and safe copy constructor

/// first line in file muys be : boa1

class level_info{
public:
    /// \brief used to get level-identifying info
    /// \return string containing basic info about level
    std::wstring get_info();


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

    std::vector<int> number_of_pawns;
    std::vector<cell*> level;


};

std::wstring level_info::get_info() {
 std::wstring line =  level_name + " by " + author;
    if(level_beaten){
        line += " B ";
    }else line += "   ";

    if(max_iteration_beaten){
        line += " I ";
    }else line += "   ";

    if(max_piece_cost_beaten){
        line += " C ";
    }else line += "   ";
    line += "\n";
    return line;
}
unsigned int level_info::getWidth() const{
 return width;
}unsigned int level_info::getHeight() const{
 return height;
}const std::string & level_info::getLevelName() const{
 return level_name;
}const std::string & level_info::getAuthor() const{
 return author;
}difficulty level_info::getLevelDifficulty() const{
 return level_difficulty;
}bool level_info::isLevelBeaten() const{
 return level_beaten;
}unsigned int level_info::getMaxIteration() const{
 return max_iteration;
}bool level_info::isMaxIterationBeaten() const{
 return max_iteration_beaten;
}unsigned int level_info::getMaxPieceCost() const{
 return max_piece_cost;
}bool level_info::isMaxPieceCostBeaten() const{
 return max_piece_cost_beaten;
}game_goal level_info::getGoalOfTheLevel() const{
 return goal_of_the_level;
}


#endif //BLOCK_O_AUTOMATA_LEVEL_INFO_H
