//
// Created by pc on 12.05.2021.
//

#include "level_pick.h"

using namespace lc;

PlayerAction LevelPick::SelectLevel() {

  loaded_levels_ = {};

  PlayerAction command = Ui();

  if (command == QUIT_GAME)
    return QUIT_GAME;
  else if (command == ENTER_EDITOR)
    return ENTER_EDITOR;

  Load(directory_path_ + loaded_levels_[cursor_position_]);

  return PLAY_LEVEL;
}

PlayerAction LevelPick::Ui() {

  Levelvec levels;

  ReadDirectory(directory_path_, loaded_levels_);

  LoadLevels(loaded_levels_, levels, directory_path_);

  unsigned char k;

  while (2 > 1) {

    DisplayUi();

    k = GetKey();

    switch (k) {
    case 'w':
      --cursor_position_;
      if (cursor_position_ < 0)
        cursor_position_ =
            levels.size() + 1; // keep cursor_position in (range of vector +1)
      break;

    case 's':
      ++cursor_position_;
      if (cursor_position_ > levels.size() + 1)
        cursor_position_ = 0;

      break;
    case 'r':

      levels.clear();
      loaded_levels_.clear();

      ReadDirectory(directory_path_, loaded_levels_);

      LoadLevels(loaded_levels_, levels, directory_path_);
      break;

    case 'q':
    case 27:
      return QUIT_GAME;

    case 'e':
    case 13:
      if (cursor_position_ < loaded_levels_.size())
        return PLAY_LEVEL;
      else if (cursor_position_ == loaded_levels_.size())
        return ENTER_EDITOR;

      else if (cursor_position_ == loaded_levels_.size() + 1)
        return QUIT_GAME;

    default:
      break;
    }
  }
}

LevelInfo LevelPick::GetLevel() { return LevelInfo(*this); }

void ReadDirectory(const std::string &name, Stringvec &v) {
  std::string pattern(name);
  pattern.append("*.txt");
  WIN32_FIND_DATA data;
  HANDLE hFind;
  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {

    do {
      v.push_back(data.cFileName);
    } while (FindNextFile(hFind, &data) != 0);
    FindClose(hFind);
  }
}

void LoadLevels(Stringvec &file_paths, Levelvec &levels,
                std::string &directory_path) {

  for (auto i : file_paths) {
    levels.push_back(LevelInfo());
    levels.back().Load(directory_path + i);
  }
}