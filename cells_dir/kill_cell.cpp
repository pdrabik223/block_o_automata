//
// Created by pc on 04.05.2021.
//

#include "kill_cell.h"
#include "empty_cell.h"

kill_cell::kill_cell( unsigned int lives) : cell(false, true), lives(lives) {}

kill_cell::kill_cell() : cell(false, true), lives(-1)  {}

void kill_cell::show_in_console_unicode() {
    std::wcout<<cc(red)<<L"\x2716 ";
}

void kill_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {

}

 void kill_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                      unsigned int w) {
     if(plane[curr_pos.reverse(move_dir,w)]->isKillable()){
         destination[curr_pos.reverse(move_dir,w)] = new empty_cell(false);
       --lives;
       if(lives == 0) {
           destination[curr_pos.toUint(w)] = new empty_cell(false);
       }
         return;
     }else {

         plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);

         if (*destination[curr_pos.go(move_dir, w)] == t_empty) {
             // me                                      the one in front
             std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
         }
     }

}

bool kill_cell::operator==(const type& rhs) const {
    return cell_type == rhs;
}

bool kill_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon kill_cell::get_unicode() {
    return {L"\x2716 ", red};
}

type kill_cell::getCellType() const {
    return cell_type;
}

unsigned int kill_cell::getLives() const {
    return lives;
}

void kill_cell::setLives(unsigned int lives) {
    kill_cell::lives = lives;
}

std::ostream &operator<<(std::ostream &out, const kill_cell &ref) {
    out<<ref.getCellType();
    out<<" ";
    out<<ref.getLives();
    return out;
}

std::istream &operator>>(std::istream &in, kill_cell &ref) {
    int lives;
    in>>lives;
    ref.setLives(lives);
    return in;
}

