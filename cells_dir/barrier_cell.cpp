//
// Created by pc on 04.05.2021.
//

#include "barrier_cell.h"

type barrier_cell::cell_type = Barrier;

barrier_cell::barrier_cell() : cell(false, false) {}


barrier_cell::barrier_cell(bool movable) : cell(movable, false) {}

void
barrier_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
    return;
}

void
barrier_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir,
                   coord curr_pos,
                   unsigned int width) {

    if (!movable) return;


    plane[curr_pos.go(move_dir, width)]->move(plane, destination, move_dir, curr_pos.go(move_dir), width);


    if (*destination[curr_pos.go(move_dir, width)] == Empty) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(width)], destination[curr_pos.go(move_dir, width)]);
    }


}

bool barrier_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool barrier_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon barrier_cell::get_unicode() {
    if (movable) return {9634, gray};
    else return {9635, gray};
}

type barrier_cell::getCellType() const {
    return cell_type;
}

void barrier_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();
    out << " ";
    out << isMovable();
}

barrier_cell *barrier_cell::clone() {


    return new barrier_cell(*this);
}

