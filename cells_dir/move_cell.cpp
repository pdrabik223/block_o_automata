//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"
#include "EmptyCell.h"
Type MoveCell::cell_type_ = MOVE;
MoveCell::MoveCell() : Cell(true, true),
                         move_direction(left) {}

MoveCell::MoveCell(direction move_direction) : Cell(true, true),
                                                move_direction(move_direction) {}

void MoveCell::Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) {

  plane[curr_pos.go(move_direction, w)]->Move(
      plane, destination, move_direction, curr_pos.go(move_direction), w);

    if (*plane[curr_pos.go(move_direction, w)] == EMPTY) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_direction, w)]);
    }


}

void MoveCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
                unsigned int width) {
    //  has_been_moved = true;
    plane[curr_pos.go(move_dir, width)]->Move(plane, destination, move_dir,
                                              curr_pos.go(move_dir), width);


    if (*destination[curr_pos.go(move_dir, width)] == EMPTY) {
        // me                                      the one in front

        std::swap(destination[curr_pos.toUint(width)], destination[curr_pos.go(move_direction, width)]);
    }

}

bool MoveCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool MoveCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

void MoveCell::SetMoveDirection(direction move_direction) {
    move_direction = move_direction;
}

icon MoveCell::GetUnicode() {

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

direction MoveCell::GetMoveDirection() const {
    return move_direction;
}

Type MoveCell::GetCellType() const {
    return cell_type_;
}

void MoveCell::RotateRight() noexcept {

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

void MoveCell::OutputFoFile(std::ostream &out) {
    out << (int)GetCellType();
    out << " ";
    out << (int)GetMoveDirection();
}

MoveCell *MoveCell::Clone() {
    return new MoveCell(*this);
}



