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

void kill_cell::action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) {

}
 // todo position inplane must be changed to current position
 // this idea of look backward go forward update if one before moved is nice
 // but this chank of code must! be minimised
void kill_cell::move(std::vector<cell *> &plane, direction move_to, unsigned int h, unsigned int w,
                     coord position_in_plane) {

    switch (move_to) {
        case left:
            if(plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)]->isKillable()) {
                plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)] = new empty_cell(false);
                lives--;
                if (lives == 0)
                    plane[toUint(position_in_plane,w)] = new empty_cell(false);
                return;
            }else
                plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)]->
                move(plane, left, h, w,position_in_plane);
            break;
        case right:
            if(plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)]->isKillable()) {
                plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)] = new empty_cell(false);
                lives--;
                if (lives == 0)
                    plane[toUint(position_in_plane,w)] = new empty_cell(false);
                return;
            }else
                plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)]->
                        move(plane, left, h, w,position_in_plane);
            break;
        case up:
            if(plane[toUint({position_in_plane.x+1, position_in_plane.y }, w)]->isKillable()) {
                plane[toUint({position_in_plane.x+1, position_in_plane.y }, w)] = new empty_cell(false);
                lives--;
                if (lives == 0)
                    plane[toUint(position_in_plane,w)] = new empty_cell(false);
                return;
            }else
                plane[toUint({position_in_plane.x-1, position_in_plane.y  }, w)]->
                        move(plane, left, h, w, position_in_plane);
            break;  break;
        case down:
            plane[toUint({position_in_plane.x - 1, position_in_plane.y}, w)];
            break;
    }

    switch (move_to) {
        case left:
           if( plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)]->getCellName() == "empty_cell"){
               plane[toUint({position_in_plane.x, position_in_plane.y - 1}, w)] = new kill_cell(lives);
               plane[toUint(position_in_plane,w)] = new empty_cell(false);

           }
            break;
        case right:
            if( plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)]->getCellName() == "empty_cell"){
                plane[toUint({position_in_plane.x, position_in_plane.y + 1}, w)] = new kill_cell(lives);
                plane[toUint(position_in_plane,w)] = new empty_cell(false);
            }
            break;
        case up:
            if( plane[toUint({position_in_plane.x-1, position_in_plane.y }, w)]->getCellName() == "empty_cell"){
                plane[toUint({position_in_plane.x-1, position_in_plane.y }, w)] = new kill_cell(lives);
                plane[toUint(position_in_plane,w)] = new empty_cell(false);
            } break;
        case down:
            if( plane[toUint({position_in_plane.x+1, position_in_plane.y }, w)]->getCellName() == "empty_cell"){
                plane[toUint({position_in_plane.x+1, position_in_plane.y }, w)] = new kill_cell(lives);
                plane[toUint(position_in_plane,w)] = new empty_cell(false);
            }
            break;
    }

}

