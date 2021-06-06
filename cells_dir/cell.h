//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELL_H
#define BLOCK_O_AUTOMATA_CELL_H

#include <cassert>
#include <iostream>
#include <vector>

#include "../windows_console_tools/win_colors.h"

#include "../windows_console_tools/coord.h"
#include "../windows_console_tools/icon.h"



//todo smart pointers to minimize mem leaks



/// type of the cell, used to identify cell by it's role
enum type {

    Cell = 1,
    Barrier = 2,
    Move = 3,
    Kill = 4,
    Spawn = 5,
    Turn = 6,
    Goal = 7,
    Empty = 8

};

class cell {


public:
    cell();

    cell(bool movable, bool killable);

    virtual cell &operator=(const cell &other) = default;

    bool isMovable() const;

    void setMovable(bool movable);

    void setKillable(bool killable);

    virtual void rotateRight() noexcept { assert(false); };

    bool isKillable() const;

    virtual icon get_unicode() {
        assert(false);
        return icon();
    };


    virtual void
    move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
         unsigned int width) {
        assert(false);
    };

    virtual void
    action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) {
        assert(false);
    };

    virtual bool operator==(const type &rhs) const;

    virtual bool operator!=(const type &rhs) const;

    virtual type getCellType() const;

    virtual void output_fo_file(std::ostream &out) { assert(false); };

    virtual cell* clone() { return this; };

    static type cell_type;
protected:
    /// can be moved/rotated by other cells
    bool movable;
    /// can this cell be killed
    bool killable;


};



#endif //BLOCK_O_AUTOMATA_CELL_H
