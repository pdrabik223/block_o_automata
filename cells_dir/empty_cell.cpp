//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

Type EmptyCell::cell_type_ = EMPTY;

EmptyCell::EmptyCell() : Cell(false, true), locked(true) {};

EmptyCell::EmptyCell(bool locked) : Cell(false, true), locked(locked) {}

void EmptyCell::Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) {}

void EmptyCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
                 unsigned int width) {

//    if (*plane[curr_pos.go(move_dir, w)] == Empty) {
//        // me                                      the one in front
//        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
//    }

}

bool EmptyCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool EmptyCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

icon EmptyCell::GetUnicode() {

    if (locked) return {' ', gray};
    else return {8226, gray};

}

Type EmptyCell::GetCellType() const {
    return cell_type_;
}

std::istream &operator>>(std::istream &in, EmptyCell &ref) {

    bool locked;
    in >> locked;
    ref.SetLocked(locked);
    return in;

}

bool EmptyCell::IsLocked() const {
    return locked;
}

void EmptyCell::SetLocked(bool locked) {
    locked = locked;
}

void EmptyCell::OutputFoFile(std::ostream &out) {
    out << (int)GetCellType();
    out << " ";
    out << IsLocked();
}

EmptyCell *EmptyCell::Clone() {
    return new EmptyCell(*this);
}



