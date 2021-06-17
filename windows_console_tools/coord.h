//
// Created by studio25 on 26.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_COORD_H_
#define BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_COORD_H_

#include <cassert>


/// used by few of the cells
/// the plane is always orientated the same way
/// so up is north on plane
/// there can be made some transformation
enum Direction { LEFT, RIGHT, UP, DOWN };

/// coord is a public class that handles movement and positioning on the grid
class Coord {

public:
  Coord(unsigned int x, unsigned int y) : x_(x), y_(y) {}



    /// \return create new object moved by one spot in direction
    /// \param dir direction of the movement
  Coord Go(Direction dir) const;

    /// goes in Reverse direction
  Coord Reverse(Direction dir) const;

    /// \return create new coordinates in 1D plane from 2D coord
    /// \param dir direction of the movement
    /// \param w given width of a 2D representation of nn plane
    unsigned Go(Direction dir, unsigned w) const;

    unsigned Reverse(Direction dir, unsigned w) const;

    /// \return moves coordinates in chosen direction by one value
    /// \param dir direction of the movement
    void MoveBy(Direction dir);

    /// \return 1d representation of the coord
    /// \param w given width of a 2D representation of nn plane
    unsigned ToUint(unsigned w) const;

    bool operator<(const Coord &rhs) const;

    bool operator>(const Coord &rhs) const;

    bool operator<=(const Coord &rhs) const;

    bool operator>=(const Coord &rhs) const;

    bool operator==(const Coord &rhs) const;

    bool operator!=(const Coord &rhs) const;

    unsigned x_;
    unsigned y_;

};


#endif // BLOCK_O_AUTOMATA_WINDOWS_CONSOLE_TOOLS_COORD_H_
