//
// Created by pc on 12.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PICK_H_
#define BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PICK_H_

#include "../windows_console_tools/win_colors.h"
#include "level_info.h"

#include <iostream>
#include <string>

#include <Windows.h>
#include <chrono>
#include <thread>
#include <vector>

#include <conio.h>

typedef std::vector<std::string> Stringvec;

typedef std::vector<LevelInfo> Levelvec;

void ReadDirectory(const std::string &name, Stringvec &v);

void LoadLevels(Stringvec &file_paths, Levelvec &levels,
                std::string &directory_path);

namespace lc {
enum PlayerAction { PLAY_LEVEL, ENTER_EDITOR, QUIT_GAME };

class LevelPick : public LevelInfo {
public:
  LevelPick() : LevelInfo() {}

  PlayerAction SelectLevel();

  LevelInfo GetLevel();

  virtual void DisplayUi(){};

  virtual unsigned char GetKey() {
    assert(false);
    return -1;
  };

protected:
  /// player Ui, it needs to be done better
  /// \return  path to chosen folder
  ///  or command to enter edit mode
  ///  or command to quit game
  PlayerAction Ui();

  unsigned cursor_position_ = 0;

  std::string directory_path_ =
      "C:\\Users\\studio25\\Documents\\block_o_automata\\levels\\";

  Stringvec loaded_levels_ = {};
};

} // namespace lc
#endif // BLOCK_O_AUTOMATA_LEVEL_DIR_LEVEL_PICK_H_
