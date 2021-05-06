//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELL_H
#define BLOCK_O_AUTOMATA_CELL_H
#include <cassert>
#include <iostream>
#include <vector>

#include "../windows_console_tools/win_colors.h"

static unsigned creation_order =0;

/// used by few of the cells
/// the plane is always orientated the same way
/// so up is north on plane
/// there can be made some transformation
enum direction {
    left,
    right,
    up,
    down
};


struct coord{
    coord(unsigned int x, unsigned int y): x(x), y(y) {}
    unsigned x;
    unsigned y;
};

unsigned toUint(coord position, unsigned w){
    return position.x*w+position.y;

}
class cell {


public:
    cell();

    cell(bool movable, bool killable);

   virtual  cell& operator=(const cell& other) = default;

    bool isMovable() const;

    void setMovable(bool movable);

    void setKillable(bool killable);

    bool isKillable() const;

    virtual void show_in_console_unicode(){}

    virtual void move(std::vector<cell *> &plane, direction move_to, unsigned h, unsigned w, coord position_in_plane) {assert(false);};
    virtual void action(std::vector<cell *> &plane, unsigned h, unsigned w, coord position_in_plane) {};

    const std::string &getCellName() const;

protected:
    /// can be moved/rotated by other cells
    bool movable;
    /// can this cell be killed
    bool killable;

    unsigned local_creation_time;
    std::string cell_name = "cell";

};


#endif //BLOCK_O_AUTOMATA_CELL_H
