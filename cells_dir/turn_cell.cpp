//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"
#include "move_cell.h"

Type TurnCell::cell_type_ = TURN;

TurnCell::TurnCell() : Cell(false, true),

                         turn_direction(LEFT) {}

TurnCell::TurnCell(Direction turn_direction) : Cell(false, true),

                                                turn_direction(turn_direction) {}

void TurnCell::Action(const std::vector<Cell *> &plane, unsigned w,
                      Coord curr_pos, std::vector<Cell *> &destination) {}

void TurnCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, Direction move_dir,
                    Coord curr_pos,
                unsigned int width) {

  plane[curr_pos.Go(turn_direction, width)]->Move(
      plane, destination, turn_direction, curr_pos.Go(turn_direction), width);


    if (*destination[curr_pos.Go(turn_direction, width)] == EMPTY ||
      curr_pos.Go(turn_direction, width) == curr_pos.Reverse(move_dir, width)) {

        // me                                      the one in front
        std::swap(destination[curr_pos.Reverse(move_dir, width)], destination[curr_pos.Go(turn_direction, width)]);

        if (*destination[curr_pos.Go(turn_direction, width)] == MOVE)
            destination[curr_pos.Go(turn_direction, width)] = new MoveCell(turn_direction);

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
        case LEFT:
            return {11164, BLUE};

        case RIGHT:
            return {11166, BLUE};

        case UP:
            return {11165, BLUE};

        case DOWN:
            return {11167, BLUE};
        default:
            return icon();
    }

}

Direction TurnCell::GetTurnDirection() const {
    return turn_direction;
}

Type TurnCell::GetCellType() const {
    return cell_type_;
}


void TurnCell::RotateRight() noexcept {
    switch (turn_direction) {
        case LEFT:
            turn_direction = UP;
            break;
        case RIGHT:
            turn_direction = DOWN;
            break;
        case DOWN:
            turn_direction = LEFT;
            break;
        case UP:
            turn_direction = RIGHT;
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

