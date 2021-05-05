//
// Created by pc on 04.05.2021.
//

#include "spawn_cell.h"

spawn_cell::spawn_cell(bool movable, unsigned int lives, direction spawnDirection) : cell(movable, true),
                                                                                     lives(lives),
                                                                                     spawn_direction(spawnDirection) {}

spawn_cell::spawn_cell(bool movable, direction spawnDirection) : cell(movable, true),
                                                                 lives(-1),
                                                                 spawn_direction(spawnDirection) {}
