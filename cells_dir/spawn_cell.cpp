//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"
#include "barrier_cell.h"
#include "goal_cell.h"
#include "kill_cell.h"
#include "move_cell.h"
#include "turn_cell.h"

type spawn_cell::cell_type = Spawn;


spawn_cell::spawn_cell() : cell(true, true),
                           spawn_direction(left) {}


spawn_cell::spawn_cell(direction spawnDirection) : cell(true, true),
                                                   spawn_direction(spawnDirection) {}


void
spawn_cell::action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
    if (*plane[curr_pos.go(spawn_direction, w)] != Empty)
        plane[curr_pos.go(spawn_direction, w)]->
                move(plane, destination, spawn_direction, curr_pos.go(spawn_direction), w);

    if (*destination[curr_pos.go(spawn_direction, w)] == Empty &&
        *destination[curr_pos.reverse(spawn_direction, w)] != Empty) {

        cell *cell_ptr = plane[curr_pos.reverse(spawn_direction, w)];

        destination[curr_pos.go(spawn_direction, w)] = cell_ptr->clone();

    }
}

void
spawn_cell::move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
                 unsigned int w) {
    plane[curr_pos.go(move_dir, w)]->move(plane, destination, move_dir, curr_pos.go(move_dir), w);

    if (*destination[curr_pos.go(move_dir, w)] == Empty) {
        // me                                      the one in front
        std::swap(destination[curr_pos.toUint(w)], destination[curr_pos.go(move_dir, w)]);
    }
}

bool spawn_cell::operator==(const type &rhs) const {
    return cell_type == rhs;
}

bool spawn_cell::operator!=(const type &rhs) const {
    return cell_type != rhs;
}

icon spawn_cell::get_unicode() {

    switch (spawn_direction) {
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

direction spawn_cell::getSpawnDirection() const {
    return spawn_direction;
}

void spawn_cell::setSpawnDirection(direction spawnDirection) {
    spawn_direction = spawnDirection;
}

type spawn_cell::getCellType() const {
    return cell_type;
}


void spawn_cell::rotateRight() noexcept {
    switch (spawn_direction) {
        case left:
            spawn_direction = up;
            break;
        case right:
            spawn_direction = down;
            break;
        case down:
            spawn_direction = left;
            break;
        case up:
            spawn_direction = right;
            break;

    }
}

void spawn_cell::output_fo_file(std::ostream &out) {
    out << (int) getCellType();
    out << " ";
    out << (int) getSpawnDirection();
}

spawn_cell *spawn_cell::clone() {
    return new spawn_cell(*this);
}

