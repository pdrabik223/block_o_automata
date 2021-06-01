//
// Created by pc on 04.05.2021.
//

#include "empty_cell.h"

empty_cell::empty_cell() : cell(false, true), locked(true) {};


empty_cell::empty_cell(bool locked) : cell(false, true), locked(locked) {}

void
empty_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {}

void
empty_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                 unsigned int w) {

    if (*plane[curr_pos.go(move_dir, w)] == Empty) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
    }

}

bool empty_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool empty_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon empty_cell::get_unicode() {

    if (locked) return {' ', gray};
    else return {8226, gray};

}

type empty_cell::getCellType() const {
    return cell_type;
}

std::ostream &operator<<(std::ostream &out, const empty_cell &ref) {

    out << ref.getCellType();
    out << " ";
    out << ref.isLocked();
    return out;
}

std::istream &operator>>(std::istream &in, empty_cell &ref) {

    bool locked;
    in >> locked;
    ref.setLocked(locked);
    return in;

}

bool empty_cell::isLocked() const {
    return locked;
}

void empty_cell::setLocked(bool locked) {
    locked = locked;
}

void empty_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();
    out << " ";
    out << isLocked();
}



