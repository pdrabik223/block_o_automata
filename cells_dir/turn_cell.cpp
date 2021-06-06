//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"
#include "move_cell.h"

type turn_cell::cell_type = Turn;

turn_cell::turn_cell() : cell(false, true),

                         turn_direction(left) {}


turn_cell::turn_cell(direction turnDirection) : cell(false, true),

                                                turn_direction(turnDirection) {}

void
turn_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {}

void
turn_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int width) {

    plane[curr_pos.go(turn_direction, width)]->move(plane, destination, turn_direction, curr_pos.go(turn_direction), width);


    if (*destination[curr_pos.go(turn_direction, width)] == Empty ||
        curr_pos.go(turn_direction, width) == curr_pos.reverse(move_dir, width)) {

        // me                                      the one in front
        std::swap(destination[curr_pos.reverse(move_dir, width)], destination[curr_pos.go(turn_direction, width)]);

        if (*destination[curr_pos.go(turn_direction, width)] == Move)
            destination[curr_pos.go(turn_direction, width)] = new move_cell(turn_direction);

    }


}

bool turn_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool turn_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon turn_cell::get_unicode() {
    switch (turn_direction) {
        case left:
            return {11164, blue};

        case right:
            return {11166, blue};

        case up:
            return {11165, blue};

        case down:
            return {11167, blue};
        default:
            return icon();
    }

}

direction turn_cell::getTurnDirection() const {
    return turn_direction;
}

type turn_cell::getCellType() const {
    return cell_type;
}


void turn_cell::rotateRight() noexcept {
    switch (turn_direction) {
        case left:
            turn_direction = up;
            break;
        case right:
            turn_direction = down;
            break;
        case down:
            turn_direction = left;
            break;
        case up:
            turn_direction = right;
            break;

    }
}

void turn_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();
    out << " ";
    out << (int) getTurnDirection();
}

turn_cell *turn_cell::clone() {
    return new turn_cell(*this);
}

