//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_COORD_H
#define BLOCK_O_AUTOMATA_COORD_H

#include <cassert>


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

/// coord is a public class that handles movement and positioning on the grid
class coord {

public:
    coord(unsigned int x, unsigned int y) : x(x), y(y) {}



    /// \return create new object moved by one spot in direction
    /// \param dir direction of the movement
    coord go(direction dir) const;

    /// goes in reverse direction
    coord reverse(direction dir) const;

    /// \return create new coordinates in 1D plane from 2D coord
    /// \param dir direction of the movement
    /// \param w given width of a 2D representation of nn plane
    unsigned go(direction dir, unsigned w) const;

    unsigned reverse(direction dir, unsigned w) const;

    /// \return moves coordinates in chosen direction by one value
    /// \param dir direction of the movement
    void move_by(direction dir);

    /// \return 1d representation of the coord
    /// \param w given width of a 2D representation of nn plane
    unsigned toUint(unsigned w) const;

    bool operator<(const coord &rhs) const;

    bool operator>(const coord &rhs) const;

    bool operator<=(const coord &rhs) const;

    bool operator>=(const coord &rhs) const;

    bool operator==(const coord &rhs) const;

    bool operator!=(const coord &rhs) const;

    unsigned x;
    unsigned y;

};


#endif //BLOCK_O_AUTOMATA_COORD_H
