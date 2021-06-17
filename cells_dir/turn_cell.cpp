//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"
#include "move_cell.h"

Type TurnCell::cell_type_ = TURN;

TurnCell::TurnCell() : Cell(false, true),

                         turn_direction(left) {}

TurnCell::TurnCell(direction turn_direction) : Cell(false, true),

                                                turn_direction(turn_direction) {}

void TurnCell::Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) {}

void TurnCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int width) {

  plane[curr_pos.go(turn_direction, width)]->Move(
      plane, destination, turn_direction, curr_pos.go(turn_direction), width);


    if (*destination[curr_pos.go(turn_direction, width)] == EMPTY ||
        curr_pos.go(turn_direction, width) == curr_pos.reverse(move_dir, width)) {

        // me                                      the one in front
        std::swap(destination[curr_pos.reverse(move_dir, width)], destination[curr_pos.go(turn_direction, width)]);

        if (*destination[curr_pos.go(turn_direction, width)] == MOVE)
            destination[curr_pos.go(turn_direction, width)] = new MoveCell(turn_direction);

    }


}

bool TurnCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool TurnCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

icon TurnCell::GetUnicode() {
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

direction TurnCell::GetTurnDirection() const {
    return turn_direction;
}

Type TurnCell::GetCellType() const {
    return cell_type_;
}


void TurnCell::RotateRight() noexcept {
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

void TurnCell::OutputFoFile(std::ostream &out) {
    out << (int)GetCellType();
    out << " ";
    out << (int)GetTurnDirection();
}

TurnCell *TurnCell::Clone() {
    return new TurnCell(*this);
}

