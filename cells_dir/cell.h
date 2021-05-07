//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_CELL_H
#define BLOCK_O_AUTOMATA_CELL_H

#include <cassert>
#include <iostream>
#include <vector>

#include "../windows_console_tools/win_colors.h"

#include "../cell_tools.h"

static unsigned creation_order = 0;





class cell {


public:
    cell();

    cell(bool movable, bool killable);

    virtual cell &operator=(const cell &other) = default;

    bool isMovable() const;

    void setMovable(bool movable);

    void setKillable(bool killable);

    bool isKillable() const;

    virtual void show_in_console_unicode() { assert(false); };

    virtual void move(std::vector<cell *> &plane, direction move_dir, unsigned int w, coord curr_pos) {
        assert(false);
    };

    virtual void action(std::vector<cell *> &plane, unsigned w, coord curr_pos) {assert(false);};

   virtual bool operator==(const type &rhs) const;

   virtual  bool operator!=(const type &rhs) const;

protected:
    /// can be moved/rotated by other cells
    bool movable;
    /// can this cell be killed
    bool killable;

    unsigned local_creation_time;

    type cell_type = t_cell;

};


#endif //BLOCK_O_AUTOMATA_CELL_H
