//
// Created by pc on 11.05.2021.
//

#include "level_info.h"


std::string CurrentDate() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

std::wstring LevelInfo::GetInfo() const {
    std::string line;
    line += level_name_;
    line += " by ";
    line += author_;

    std::wstring wline;
    for (auto i:line)
        wline.push_back((wchar_t) i);

    return wline;
}

unsigned int LevelInfo::GetWidth() const {
    return width_;
}

unsigned int LevelInfo::GetHeight() const {
    return height_;
}

LevelInfo::LevelInfo(unsigned int height, unsigned int width) : width_(width), height_(height) {

  level_name_ = "noname";
  author_ = "noname";

  level_beaten_ = false;

  max_iteration_ = 0;
  max_iteration_beaten_ = false;

  max_piece_cost_ = 0;
  max_piece_cost_beaten_ = false;



    for (int i = 0; i < width * height; ++i) {

        if (i % width == 0 ||
            i / width == 0 ||
            i / width == (height - 1) ||
            i % width == (height - 1))
          level_.push_back(new BarrierCell(false));

        else
          level_.push_back(new EmptyCell(true));
    }

}


void LevelInfo::Resize(unsigned int new_height, unsigned int new_width) {
    std::vector<Cell *> level_copy = level_;
    unsigned i = 0;
    level_.clear();
    level_.reserve(new_height * new_width);

    for (int x = 0; x < new_height; x++) {
        for (int y = 0; y < new_width; y++) {
            if (x < height_ && y < width_) {

              level_.push_back(level_copy[i]);
                ++i;

            } else
              level_.push_back(new EmptyCell(true));
        }
        if (new_width < width_) i += width_ - new_width;
    }

    width_ = new_width;
    height_ = new_height;
}

LevelInfo::LevelInfo() {

  level_name_ = "noname";
  author_ = "noname";

  level_beaten_ = false;

  max_iteration_ = 0;
  max_iteration_beaten_ = false;

  max_piece_cost_ = 0;
  max_piece_cost_beaten_ = false;

  width_ = 1;
  height_ = 1;

    for (int i = 0; i < width_ * height_; i++)
      level_.push_back(new EmptyCell(false));

}

void LevelInfo::Save() {

    std::ofstream myfile;
    std::string file_path;

    if (level_name_ == "noname") {
        std::string date = CurrentDate().erase(0, 11);
        for (char &i:date)
            if (i == ':') i = '_';
        file_path = "../\\levels\\" + date + ".txt";
        level_name_ = "noname" + date;

    } else
        file_path = "../\\levels\\" + level_name_ + ".txt";


    myfile.open(file_path);
    if (!myfile.is_open()) {
        std::cout << "\nfile is bad ";
        return;
    }


    myfile << level_name_ << "\n"; // every field is separated by new line
    myfile << author_ << "\n";

    myfile << level_beaten_ << "\n";

    myfile << max_iteration_ << "\n";
    myfile << max_iteration_beaten_ << "\n";

    myfile << max_piece_cost_ << "\n";
    myfile << max_piece_cost_beaten_ << "\n";

    myfile << width_ << "\n";
    myfile << height_ << "\n";

    for (Cell *piece : level_) {
      piece->OutputFoFile(myfile);
        myfile << " ";

    }
    myfile.close();
}

void LevelInfo::Load(const std::string &path) {
    std::ifstream myfile;
    myfile.open(path);
    std::string file_header;

    if (!myfile.good()) {

        std::cout << "\nfile is fucked ";
        assert(false);
        return;
    }


    myfile >> level_name_; // every field is separated by new line

    myfile >> author_;


    myfile >> level_beaten_;

    myfile >> max_iteration_;
    myfile >> max_iteration_beaten_;

    myfile >> max_piece_cost_;
    myfile >> max_piece_cost_beaten_;

    myfile >> width_;
    myfile >> height_;
    level_ = {};

    int temp_int;
    for (int i = 0; i < width_ * height_; i++) {

        myfile >> temp_int;

        switch ((Type) temp_int) {
            case BARRIER: {

                bool is_movable;
                myfile >> is_movable;

                level_.push_back(new BarrierCell(is_movable));
            }
                break;
            case MOVE: {

                int move_direction;
                myfile >> move_direction;

                level_.push_back(new MoveCell((Direction) move_direction));
            }
                break;
            case KILL: {

              level_.push_back(new KillCell());

            }
                break;
            case SPAWN: {

                int spawn_direction;
                myfile >> spawn_direction;

                level_.push_back(new SpawnCell((Direction) spawn_direction));
            }
                break;
            case TURN: {

                int turn_direction;
                myfile >> turn_direction;

                level_.push_back(new TurnCell((Direction) turn_direction));

            }
                break;
            case EMPTY: {
                bool locked;
                myfile >> locked;
                level_.push_back(new EmptyCell(locked));

            }
                break;
            case GOAL: {

              level_.push_back(new GoalCell());

            }
                break;
            case CELL: {
                assert(false);
                /// here comes exception
            }
                break;
            default:
                assert(false);
                /// here comes exception
        }
    }

    myfile.close();
}

Cell &LevelInfo::GetCell(unsigned int h, unsigned int w) {
    return *level_[h * width_ + w];
}

Cell &LevelInfo::GetCell(Coord position) {
    return *level_[position.x_ * width_ + position.y_];
}

Cell *&LevelInfo::operator[](unsigned position) {
    return level_[position];
}

Cell *&LevelInfo::operator[](Coord position) {
    return level_[position.x_ * width_ + position.y_];
}

const std::vector<Cell *> &LevelInfo::GetLevel() const {
    return level_;
}

void LevelInfo::SetCell(Coord position, Cell *target) {
  level_[position.x_ * width_ + position.y_] = new Cell(*target);
}


void LevelInfo::CopyCell(Coord position, Cell *target) {

  level_[position.x_ * width_ + position.y_] = target->Clone();
}
