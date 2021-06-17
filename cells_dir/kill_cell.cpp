//
// Created by pc on 04.05.2021.
//

#include "kill_cell.h"
#include "empty_cell.h"
Type KillCell::cell_type_ = KILL;

KillCell::KillCell() : Cell(false, true) {}

void KillCell::Action(const std::vector<Cell *> &plane, unsigned w,
                      Coord curr_pos, std::vector<Cell *> &destination) {

}

void KillCell::Move(const std::vector<Cell *> &plane,
                    std::vector<Cell *> &destination, Direction move_dir,
                    Coord curr_pos,
                unsigned int width) {
    if (plane[curr_pos.Reverse(move_dir, width)]->IsKillable()) {
        destination[curr_pos.Reverse(move_dir, width)] = new EmptyCell(true);
        return;
    } else {

      plane[curr_pos.Go(move_dir, width)]->Move(plane, destination, move_dir,
                                                curr_pos.Go(move_dir), width);

        if (*destination[curr_pos.Go(move_dir, width)] == EMPTY) {
            // me                                      the one in front
            std::swap(destination[curr_pos.ToUint(width)], destination[curr_pos.Go(move_dir, width)]);
        }
    }

}

bool KillCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool KillCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

icon KillCell::GetUnicode() {
    return {10006, RED};
}

Type KillCell::GetCellType() const {
    return cell_type_;
}

void KillCell::OutputFoFile(std::ostream &out) {
    out << (int)GetCellType();

}

KillCell *KillCell::Clone() {
    return new KillCell(*this);
}



