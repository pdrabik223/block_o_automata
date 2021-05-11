//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"
#include "empty_cell.h"

move_cell::move_cell() : cell(true, true),
                         move_direction(left) {}

move_cell::move_cell(direction moveDirection) : cell(true, true),
                                                move_direction(moveDirection) {}

void move_cell::show_in_console_unicode() {
    switch (move_direction) {

        case left:
            std::wcout << cc(yellow) << L"\x2B9C ";
            break;
        case right :
            std::wcout << cc(yellow) << L"\x2B9E ";
            break;
        case up:
            std::wcout << cc(yellow) << L"\x2B9D ";
            break;
        case down:
            std::wcout << cc(yellow) << L"\x2B9F ";
            break;
    }
}

void move_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {


        plane[curr_pos.go(move_direction, w)]->move(plane, destination, move_direction,
                                                    curr_pos.go(move_direction), w);

        if (*plane[curr_pos.go(move_direction, w)] == t_empty) {
            // me                                      the one in front
            std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_direction, w)]);
        }


    if (*plane[curr_pos.go(move_direction, w)] == t_empty) {
        // me                                      the one in front
        cell temp = *destination[curr_pos.go(move_direction, w)];
        *destination[curr_pos.go(move_direction, w)] = *destination[curr_pos.toUint(w)];
        *destination[curr_pos.toUint(w)] = temp;

    }


   // has_been_moved = false;

}

void
move_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int w) {
   //  has_been_moved = true;
    plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);


    if (*destination[curr_pos.go(move_dir, w)] == t_empty) {
        // me                                      the one in front

        cell temp = *destination[curr_pos.go(move_dir, w)];
        *destination[curr_pos.go(move_dir, w)] = *destination[curr_pos.toUint(w)];
        *destination[curr_pos.toUint(w)] = temp;

    }

}

bool move_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool move_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

void move_cell::setMoveDirection(direction moveDirection) {
    move_direction = moveDirection;
}

icon move_cell::get_unicode() {

    switch (move_direction) {

        case left:
            return {L"\x2B9C ", yellow};

        case right:
            return {L"\x2B9E ", yellow};

        case up:
            return {L"\x2B9D ", yellow};

        case down:
            return {L"\x2B9F ", yellow};


    }

}

direction move_cell::getMoveDirection() const {
    return move_direction;
}

type move_cell::getCellType() const {
    return cell_type;
}

std::ostream &operator<<(std::ostream &out, const move_cell &ref) {
    out<<ref.getCellType();
    out<<" ";
    out<<ref.getMoveDirection();
    return out;

}

std::istream &operator>>(std::istream &in, move_cell &ref) {
    int moveDirection;
    in>>moveDirection;

    ref.setMoveDirection((direction) moveDirection);
    return in;
}


