//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"
#include "barrier_cell.h"
#include "goal_cell.h"
#include "kill_cell.h"
#include "move_cell.h"
#include "turn_cell.h"

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

        switch (cell_ptr->getCellType()) {
            case Barrier: {

                if ((barrier_cell *) (cell_ptr)->isMovable()) {
                    destination[curr_pos.go(spawn_direction, w)] = new barrier_cell(
                            (barrier_cell *) (cell_ptr)->isMovable());
                }
                break;
            }
            case Goal: {

                destination[curr_pos.go(spawn_direction, w)] = new goal_cell();
                break;
            }
            case Kill: {

                destination[curr_pos.go(spawn_direction, w)] = new kill_cell();

                break;
            }
            case Move: {

                destination[curr_pos.go(spawn_direction, w)] = new move_cell(
                        ((move_cell *) cell_ptr)->getMoveDirection());

                break;
            }
            case Spawn: {


                destination[curr_pos.go(spawn_direction, w)] = new spawn_cell(
                        ((spawn_cell *) cell_ptr)->getSpawnDirection());

                break;
            }
            case Turn: {
                turn_cell temp = *((turn_cell *) cell_ptr);
                destination[curr_pos.go(spawn_direction, w)] = new turn_cell(
                        ((turn_cell *) cell_ptr)->getTurnDirection());
                break;
            }
            case Empty:
                break;

            default:

                assert(false);
                return;
        }


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
            return {L"\x2B9C ", green};
        case right:
            return {L"\x2B9E ", green};
        case up:
            return {L"\x2B9D ", green};
        case down:
            return {L"\x2B9F ", green};
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


std::ostream &operator<<(std::ostream &out, const spawn_cell &ref) {
    out << ref.getCellType();
    out << " ";
    out << ref.getSpawnDirection();

    return out;
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

