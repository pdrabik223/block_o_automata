//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_INFO_H_
#define BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_INFO_H_

#include "../cells_dir/EmptyCell.h"
#include "../cells_dir/barrier_cell.h"
#include "../cells_dir/goal_cell.h"
#include "../cells_dir/kill_cell.h"
#include "../cells_dir/move_cell.h"
#include "../cells_dir/spawn_cell.h"
#include "../cells_dir/turn_cell.h"

#include <fstream>

#include "windows_console_tools/coord.h"
#include "windows_console_tools/icon.h"
#include <array>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <iomanip> // put_time
#include <sstream> // stringstream
#include <string>
#include <vector>

/// \return current date in form of a string
std::string CurrentDate();

//  todo strong and safe copy constructor

class LevelInfo {
public:
  /// \brief used to get level-identifying info
  /// \return string containing basic info about level
  std::wstring GetInfo() const;

  /// \brief constructor is simple
  ///  all of the fields will be accessed by set adn get functions
  LevelInfo(unsigned int height, unsigned int width);

  /// \brief no param constructor
  /// level will be as default as it gets
  LevelInfo();

  /// \return resizes field without losing data
  void Resize(unsigned int new_height, unsigned int new_width);

  /// \brief Save current state of the level on drive
  void Save();

  /// Load level to memory
  /// \param path to a desired level
  void Load(const std::string &path);

  void SetCell(coord position, Cell *target);

  void CopyCell(coord position, Cell *target);

  /// \return reference to a chosen Cell in level
  /// \param w of a chosen Cell
  /// \param wight  of a chosen Cell
  Cell &GetCell(unsigned h, unsigned w);

  /// \return reference to a chosen Cell in level
  /// \param position coordinates of wanted Cell
  Cell &GetCell(coord position);

  Cell *&operator[](unsigned position);

  Cell *&operator[](coord position);

  unsigned Size() { return width_ * height_; }

  unsigned int GetWidth() const;

  unsigned int GetHeight() const;

  const std::vector<Cell *> &GetLevel() const;

  std::string level_name_;
  std::string author_;
  bool level_beaten_;

  unsigned max_iteration_;
  bool max_iteration_beaten_;

  unsigned max_piece_cost_;
  bool max_piece_cost_beaten_;

protected:
  unsigned width_;
  unsigned height_;

  std::vector<Cell *> level_;
};

#endif // BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_INFO_H_
