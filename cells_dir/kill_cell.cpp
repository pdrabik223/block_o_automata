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

void kill_cell::action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {

}
 // todo position inplane must be changed to current position
 // this idea of look backward go forward update if one before moved is nice
 // but this chank of code must! be minimised
 void kill_cell::move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {
     if(plane[curr_pos.reverse(move_dir,w)]->isKillable()){
         plane[curr_pos.reverse(move_dir,w)] = new empty_cell(false);
       --lives;
       if(lives == 0) {
           plane[curr_pos.toUint(w)] = new empty_cell(false);
       }
         return;
     }else {

         plane[curr_pos.go(move_dir, w)]->move(plane, move_dir, w, curr_pos.go(move_dir));

         if (*plane[curr_pos.go(move_dir, w)] == t_empty) {
             // me                                      the one in front
             std::swap(plane[curr_pos.toUint(w)], plane[curr_pos.go(move_dir, w)]);
         }
     }

}

bool kill_cell::operator==(const type rhs) const {
    return cell_type == rhs;
}

bool kill_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

