//
// Created by pc on 11.05.2021.
//

#include "level_info.h"


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


level_info::level_info(unsigned int width, unsigned int height) : width(width), height(height) {


    level_name = current_date();
    author = "noname";
    level_difficulty = not_specified;
    level_beaten = false;

    max_iteration = 0;
    max_iteration_beaten = false;

    max_piece_cost = 0;
    max_piece_cost_beaten = false;

    number_of_pawns = {999, 999, 999, 999, 999};

    for (int i = 0; i < width * height; ++i) {

        if (i % width == 0 ||
            i / width == 0 ||
            i / width == (height - 1) ||
            i % width == (height - 1))
            level.push_back(new barrier_cell(false));

        else level.push_back(new empty_cell(true));
    }

}

void level_info::resize(unsigned int new_width, unsigned int new_height) {
    std::vector<cell *> level_copy = level;
    unsigned i = 0;
    level.clear();

    for (int x = 0; x < new_height; x++) {
        for (int y = 0; y < new_width; y++) {
            if (x < width && y < height) {

                level.push_back(level_copy[i]);
                ++i;

            } else level.push_back(new empty_cell(true));

        }
    }

    width = new_width;
    height = new_height;
}

level_info::level_info() {

    level_name = "noname";
    author = "noname";
    level_difficulty = not_specified;
    level_beaten = false;

    max_iteration = 0;
    max_iteration_beaten = false;

    max_piece_cost = 0;
    max_piece_cost_beaten = false;


    number_of_pawns = {999, 999, 999, 999, 999};

    width = 1;
    height = 1;

    for (int i = 0; i < width * height; i++)
        level.push_back(new empty_cell(false));

}

void level_info::save() {

    std::ofstream myfile;
    std::string file_path;

    if (level_name == "noname") {
        std::string date = current_date().erase(0, 11);
        for (char &i:date)
            if (i == ':') i = '_';
        file_path = "../\\levels" + date + ".txt";
        level_name = "noname" + date;

    } else
        file_path = "../\\levels" + level_name + ".txt";


    myfile.open(file_path);
    if (!myfile.is_open()) std::cout << "\nfile is fucked ";


    myfile << level_name << "\n"; // every field is separated by new line
    myfile << author << "\n";
    myfile << level_difficulty << "\n";
    myfile << level_beaten << "\n";

    myfile << max_iteration << "\n";
    myfile << max_iteration_beaten << "\n";

    myfile << max_piece_cost << "\n";
    myfile << max_piece_cost_beaten << "\n";


    for (int number_of_pawn : number_of_pawns)
        myfile << number_of_pawn << " ";

    myfile << "\n";
    myfile << width << "\n";
    myfile << height << "\n";

    for (cell *&i : level) {
        myfile << *i << " ";

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


    for (int &number : number_of_pawns)
        myfile >> number;

    myfile >> width;
    myfile >> height;


    for (int i = 0; i < width * height; ++i) {

        myfile >> temp_int;

        switch ((type) temp_int) {
            case Barrier: {

                bool is_movable;
                myfile >> is_movable;

                level.push_back(new barrier_cell(is_movable));
            }
                break;
            case Move: {

                int move_direction;
                myfile >> move_direction;

                level.push_back(new move_cell((direction) move_direction));
            }
                break;
            case Kill: {

                level.push_back(new kill_cell());

            }
                break;
            case Spawn: {

                int spawn_direction;
                myfile >> spawn_direction;

                level.push_back(new spawn_cell((direction) spawn_direction));
            }
                break;
            case Turn: {

                int turn_direction;
                myfile >> turn_direction;

                level.push_back(new turn_cell((direction) turn_direction));

            }
                break;
            case Empty: {
                bool locked;
                myfile >> locked;
                level.push_back(new empty_cell(locked));

            }
                break;
            case Goal: {

                level.push_back(new goal_cell());

            }
                break;
            case Cell: {
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


cell &level_info::get_cell(unsigned int h, unsigned int w) {
    return *level[h * width + w];
}

cell &level_info::get_cell(coord position) {
    return *level[position.x * width + position.y];
}

cell *&level_info::operator[](unsigned position) {
    return level[position];
}

cell *&level_info::operator[](coord position) {
    return level[position.x * width + position.y];
}

const std::vector<cell *> &level_info::getLevel() const {
    return level;
}

void level_info::set_cell(coord position, cell *target) {
    level[position.x * width + position.y] = target;
}


void level_info::copy_cell(coord position, cell *target) {
    // todo clone this shit

    switch (target->getCellType()) {
        case Barrier:
            level[position.x * width + position.y] = new barrier_cell(target->isMovable());
            break;
        case Move:
            level[position.x * width + position.y] =
                    new move_cell(((move_cell *) target)->getMoveDirection());

            break;
        case Kill:
            level[position.x * width + position.y] =
                    new kill_cell();
            break;
        case Spawn:
            level[position.x * width + position.y] =
                    new spawn_cell(((spawn_cell *) target)->getSpawnDirection());
            break;
        case Turn:
            level[position.x * width + position.y] = new turn_cell(((turn_cell *) target)->getTurnDirection());
            break;
        case Goal:
            level[position.x * width + position.y] = new goal_cell();
            break;
        case Empty:
            level[position.x * width + position.y] = new empty_cell(((empty_cell *) target)->isLocked());
            break;
        case Cell:

        default :
            assert(false);
    }

}


