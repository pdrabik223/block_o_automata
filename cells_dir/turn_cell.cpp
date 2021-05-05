//
// Created by pc on 04.05.2021.
//

#include "turn_cell.h"

turn_cell::turn_cell(unsigned int rotationsLeft, direction turnDirection) : cell(false, true),
                                                                            rotations_left(rotationsLeft),
                                                                            turn_direction(turnDirection) {}

turn_cell::turn_cell(direction turnDirection) : cell(false, true),
                                                rotations_left(-1),
                                                                           turn_direction(turnDirection) {}
