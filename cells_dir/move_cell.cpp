//
// Created by pc on 04.05.2021.
//

#include "move_cell.h"
#include "empty_cell.h"
Type MoveCell::cell_type_ = MOVE;
MoveCell::MoveCell() : Cell(true, true),
                         move_direction(LEFT) {}

MoveCell::MoveCell(Direction move_direction) : Cell(true, true),
                                                move_direction(move_direction) {}

void MoveCell::Action(const std::vector<Cell *> &plane, unsigned w,
                      Coord curr_pos, std::vector<Cell *> &destination) {

  plane[curr_pos.Go(move_direction, w)]->Move(
      plane, destination, move_direction, curr_pos.Go(move_direction), w);

    if (*plane[curr_pos.Go(move_direction, w)] == EMPTY) {
        // me                                      the one in front
        std::swap(destination[curr_pos.ToUint(w)], destination[curr_pos.Go(move_direction, w)]);
    }


}

void MoveCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, Direction move_dir,
                    Coord curr_pos,
                unsigned int width) {
    //  has_been_moved = true;
    plane[curr_pos.Go(move_dir, width)]->Move(plane, destination, move_dir,
                                              curr_pos.Go(move_dir), width);


    if (*destination[curr_pos.Go(move_dir, width)] == EMPTY) {
        // me                                      the one in front

        std::swap(destination[curr_pos.ToUint(width)], destination[curr_pos.Go(move_direction, width)]);
    }

}

bool MoveCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool MoveCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

void MoveCell::SetMoveDirection(Direction move_direction) {
    move_direction = move_direction;
}

icon MoveCell::GetUnicode() {

    switch (move_direction) {

        case LEFT:
            return {11164, YELLOW};

        case RIGHT:
            return {11166, YELLOW};

        case UP:
            return {11165, YELLOW};

        case DOWN:
            return {11167, YELLOW};
        default:
            return icon();

    }

}

Direction MoveCell::GetMoveDirection() const {
    return move_direction;
}

Type MoveCell::GetCellType() const {
    return cell_type_;
}

void MoveCell::RotateRight() noexcept {

    switch (move_direction) {
        case LEFT:
            move_direction = UP;
            break;
        case RIGHT:
            move_direction = DOWN;
            break;
        case DOWN:
            move_direction = LEFT;
            break;
        case UP:
            move_direction = RIGHT;
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



