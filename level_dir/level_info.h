//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_INFO_H
#define BLOCK_O_AUTOMATA_LEVEL_INFO_H


#include "../cells_dir/empty_cell.h"
#include "../cells_dir/barrier_cell.h"
#include "../cells_dir/move_cell.h"
#include "../cells_dir/kill_cell.h"
#include "../cells_dir/spawn_cell.h"
#include "../cells_dir/turn_cell.h"
#include "../cells_dir/goal_cell.h"

#include <fstream>

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>
#include <vector>
#include <array>
#include "windows_console_tools/coord.h"
#include "windows_console_tools/icon.h"

/// \return current date in form of a string
std::string current_date();

enum difficulty {
    not_specified,
    easy,
    medium,
    hard,
    insane
};

//  todo strong and safe copy constructor

class level_info {
public:
    /// \brief used to get level-identifying info
    /// \return string containing basic info about level
    std::wstring get_info() const;

    /// \brief constructor is simple
    ///  all of the fields will be accessed by set adn get functions
    level_info(unsigned int height, unsigned int width);

    /// \brief no param constructor
    /// level will be as default as it gets
    level_info();

    /// \return resizes field without losing data
    void resize(unsigned int new_height,unsigned int new_width);

    /// \brief save current state of the level on drive
    void save();

    /// load level to memory
    /// \param path to a desired level
    void load(const std::string &path);

    void set_cell(coord position, cell *target);

    void copy_cell(coord position, cell *target);

    /// \return reference to a chosen cell in level
    /// \param w of a chosen cell
    /// \param wight  of a chosen cell
    cell &get_cell(unsigned h, unsigned w);

    /// \return reference to a chosen cell in level
    /// \param position coordinates of wanted cell
    cell &get_cell(coord position);

    cell *&operator[](unsigned position);

    cell *&operator[](coord position);

    unsigned size() { return width * height; }


    unsigned int getWidth() const;

    unsigned int getHeight() const;

    const std::vector<cell *> &getLevel() const;


    std::string level_name;
    std::string author;
    difficulty level_difficulty; //?
    bool level_beaten;

    unsigned max_iteration;
    bool max_iteration_beaten;

    unsigned max_piece_cost;
    bool max_piece_cost_beaten;



    std::array<int, 5> number_of_pawns; //


protected:

    unsigned width;
    unsigned height;

    std::vector<cell *> level;


};

#endif //BLOCK_O_AUTOMATA_LEVEL_INFO_H
