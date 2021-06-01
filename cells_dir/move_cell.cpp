//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"
#include "empty_cell.h"

move_cell::move_cell() : cell(true, true),
                         move_direction(left) {}

move_cell::move_cell(direction moveDirection) : cell(true, true),
                                                move_direction(moveDirection) {}

void move_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {


    plane[curr_pos.go(move_direction, w)]->move(plane, destination, move_direction,
                                                curr_pos.go(move_direction), w);

    if (*plane[curr_pos.go(move_direction, w)] == Empty) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_direction, w)]);
    }


}

void
move_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int w) {
    //  has_been_moved = true;
    plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);


    if (*destination[curr_pos.go(move_dir, w)] == Empty) {
        // me                                      the one in front

        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_direction, w)]);

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
            return {11164, yellow};

        case right:
            return {11166, yellow};

        case up:
            return {11165, yellow};

        case down:
            return {11167, yellow};
        default:
            return icon();

    }

}

direction move_cell::getMoveDirection() const {
    return move_direction;
}

type move_cell::getCellType() const {
    return cell_type;
}

std::ostream &operator<<(std::ostream &out, const move_cell &ref) {
    out << ref.getCellType();
    out << " ";
    out << ref.getMoveDirection();
    return out;

}

void move_cell::rotateRight() noexcept {

    switch (move_direction) {
        case left:
            move_direction = up;
            break;
        case right:
            move_direction = down;
            break;
        case down:
            move_direction = left;
            break;
        case up:
            move_direction = right;
            break;

    }


}

void move_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();
    out << " ";
    out << (int) getMoveDirection();
}



