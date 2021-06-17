//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"
#include "barrier_cell.h"

Type SpawnCell::cell_type_ = SPAWN;

SpawnCell::SpawnCell() : Cell(true, false), spawn_direction_(LEFT) {}

SpawnCell::SpawnCell(Direction spawn_direction) : Cell(true, false), spawn_direction_(spawn_direction) {}


void SpawnCell::Action(const std::vector<Cell *> &plane, unsigned w,
                       Coord curr_pos, std::vector<Cell *> &destination) {
    if (*plane[curr_pos.Go(spawn_direction_, w)] != EMPTY)
      plane[curr_pos.Go(spawn_direction_, w)]->Move(
          plane, destination, spawn_direction_, curr_pos.Go(spawn_direction_), w);

    if (*destination[curr_pos.Go(spawn_direction_, w)] == EMPTY &&
        *destination[curr_pos.Reverse(spawn_direction_, w)] != EMPTY) {

      Cell *cell_ptr = plane[curr_pos.Reverse(spawn_direction_, w)];

        destination[curr_pos.Go(spawn_direction_, w)] = cell_ptr->Clone();

    }
}

void SpawnCell::Move(const std::vector<Cell *> &plane, std::vector<Cell *> &destination, Direction move_dir,
                     Coord curr_pos,
                 unsigned int width) {

  plane[curr_pos.Go(move_dir, width)]->Move(plane, destination, move_dir,
                                            curr_pos.Go(move_dir), width);

    if (*destination[curr_pos.Go(move_dir, width)] == EMPTY) {
        // me                                      the one in front
        std::swap(destination[curr_pos.ToUint(width)], destination[curr_pos.Go(move_dir, width)]);
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
        case LEFT:
            return {11164, GREEN};

        case RIGHT:
            return {11166, GREEN};

        case UP:
            return {11165, GREEN};

        case DOWN:
            return {11167, GREEN};
        default:
            return icon();
    }
}

Direction SpawnCell::GetSpawnDirection() const {
    return spawn_direction_;
}

void SpawnCell::SetSpawnDirection(Direction spawn_direction) {
    spawn_direction_ = spawn_direction;
}

Type SpawnCell::GetCellType() const {
    return cell_type_;
}


void SpawnCell::RotateRight() noexcept {
    switch (spawn_direction_) {
        case LEFT:
          spawn_direction_ = UP;
            break;
        case RIGHT:
          spawn_direction_ = DOWN;
            break;
        case DOWN:
          spawn_direction_ = LEFT;
            break;
        case UP:
          spawn_direction_ = RIGHT;
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

