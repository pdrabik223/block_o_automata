//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"
#include "move_cell.h"


turn_cell::turn_cell(): cell(false, true),

                        turn_direction(left) {}



turn_cell::turn_cell(direction turnDirection) : cell(false, true),

                                                turn_direction(turnDirection) {}

void turn_cell::show_in_console_unicode() {
    switch (turn_direction) {
        case left:
            std::wcout << cc(blue) << L"\x2B9C ";
            break;
        case right:
            std::wcout << cc(blue) << L"\x2B9E ";
            break;
        case up:
            std::wcout << cc(blue) << L"\x2B9D ";
            break;
        case down :
            std::wcout << cc(blue) << L"\x2B9F ";
            break;
    }
}

void turn_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {}

void
turn_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int w) {

    plane[curr_pos.go(turn_direction, w)]->move(plane, destination, turn_direction, curr_pos.go(turn_direction), w);


    if (*destination[curr_pos.go(turn_direction, w)] == Empty || curr_pos.go(turn_direction, w) == curr_pos.reverse(move_dir, w)) {

        // me                                      the one in front
        std::swap(destination[curr_pos.reverse(move_dir, w)], destination[curr_pos.go(turn_direction, w)]);

        if (*destination[curr_pos.go(turn_direction, w)] == Move)
            destination[curr_pos.go(turn_direction, w)] = new move_cell(turn_direction);

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
            return {L"\x2B9C ", blue};

        case right:
            return {L"\x2B9E ", blue};

        case up:
            return {L"\x2B9D ", blue};

        case down :
            return {L"\x2B9F ", blue};
    }

}

direction turn_cell::getTurnDirection() const {
    return turn_direction;
}

void turn_cell::setTurnDirection(direction turnDirection) {
    turn_direction = turnDirection;
}

type turn_cell::getCellType() const {
    return cell_type;
}


std::ostream &operator<<(std::ostream &out, const turn_cell &ref) {
    out << ref.getCellType();
    out << " ";
    out << ref.getTurnDirection();

    return out;
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
            turn_direction=left;
            break;
        case up:
            turn_direction = right;
            break;

    }
}

