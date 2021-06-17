//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"
#include "barrier_cell.h"

Type SpawnCell::cell_type_ = SPAWN;

SpawnCell::SpawnCell() : Cell(true, false), spawn_direction_(left) {}

SpawnCell::SpawnCell(direction spawn_direction) : Cell(true, false), spawn_direction_(spawn_direction) {}


void SpawnCell::Action(const std::vector<Cell *> &plane, unsigned w, coord curr_pos, std::vector<Cell *> &destination) {
    if (*plane[curr_pos.go(spawn_direction_, w)] != EMPTY)
      plane[curr_pos.go(spawn_direction_, w)]->Move(
          plane, destination, spawn_direction_, curr_pos.go(spawn_direction_), w);

    if (*destination[curr_pos.go(spawn_direction_, w)] == EMPTY &&
        *destination[curr_pos.reverse(spawn_direction_, w)] != EMPTY) {

      Cell *cell_ptr = plane[curr_pos.reverse(spawn_direction_, w)];

        destination[curr_pos.go(spawn_direction_, w)] = cell_ptr->Clone();

    }
}

void SpawnCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, direction move_dir, coord curr_pos,
                 unsigned int width) {

  plane[curr_pos.go(move_dir, width)]->Move(plane, destination, move_dir,
                                            curr_pos.go(move_dir), width);

    if (*destination[curr_pos.go(move_dir, width)] == EMPTY) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(width)], destination[curr_pos.go(move_dir, width)]);
    }
}

bool SpawnCell::operator==(const Type &rhs) const {
    return cell_type_ == rhs;
}

bool SpawnCell::operator!=(const Type &rhs) const {
    return cell_type_ != rhs;
}

icon SpawnCell::GetUnicode() {

    switch (spawn_direction_) {
        case left:
            return {11164, green};

        case right:
            return {11166, green};

        case up:
            return {11165, green};

        case down:
            return {11167, green};
        default:
            return icon();
    }
}

direction SpawnCell::GetSpawnDirection() const {
    return spawn_direction_;
}

void SpawnCell::SetSpawnDirection(direction spawn_direction) {
    spawn_direction_ = spawn_direction;
}

Type SpawnCell::GetCellType() const {
    return cell_type_;
}


void SpawnCell::RotateRight() noexcept {
    switch (spawn_direction_) {
        case left:
          spawn_direction_ = up;
            break;
        case right:
          spawn_direction_ = down;
            break;
        case down:
          spawn_direction_ = left;
            break;
        case up:
          spawn_direction_ = right;
            break;

    }
}

void SpawnCell::OutputFoFile(std::ostream &out) {
    out << (int)GetCellType();
    out << " ";
    out << (int)GetSpawnDirection();
}

SpawnCell *SpawnCell::Clone() {
    return new SpawnCell(*this);
}

