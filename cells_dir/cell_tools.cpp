//
// Created by pc on 07.05.2021.
//

#include "cell_tools.h"

unsigned coord::toUint(unsigned int w) const {
    assert(y < w);
    assert(w != 0);
    return x * w + y;
}

void coord::move_by(direction dir) {
    switch (dir) {
        case left:
            assert(y >= 0);
            --y;
            break;
        case right:
            ++y;
            break;
        case up:
            assert(x >= 0);
            --x;
            break;
        case down:
            ++x;
            break;
        default:
            assert(false);
            break;
    }


}

unsigned coord::reverse(direction dir, unsigned int w) const {
    assert(y < w);
    assert(w != 0);

    switch (dir) {
        case right:
            assert(y >= 0);
            return x * w + y - 1;

        case left:
            return x * w + y + 1;

        case down:
            assert(x >= 0);
            return (x - 1) * w + y;

        case up:
            return (x + 1) * w + y;

        default:
            assert(false);
            return -1;

    }
}

unsigned coord::go(direction dir, unsigned int w) const {
    assert(y <= w);
    assert(w != 0);

    switch (dir) {
        case left:
            assert(y >= 0);
            return x * w + y - 1;

        case right:
            return x * w + y + 1;

        case up:
            assert(x >= 0);
            return (x - 1) * w + y;

        case down:
            return (x + 1) * w + y;

        default:
            assert(false);
            return -1;
    }
}

coord coord::reverse(direction dir) const {
    switch (dir) {
        case right:
            assert(y >= 0);
            return {x, y - 1};

        case left:
            return {x, y + 1};

        case down:
            assert(x >= 0);
            return {x - 1, y};

        case up:
            return {x + 1, y};

        default:
            assert(false);
            return {(unsigned)-1,(unsigned)-1};

    }
}

coord coord::go(direction dir) const {
    switch (dir) {
        case left:
            assert(y >= 0);
            return {x, y - 1};

        case right:
            return {x, y + 1};

        case up:
            assert(x >= 0);
            return {x - 1, y};

        case down:
            return {x + 1, y};

        default:
            assert(false);
            return {(unsigned)-1,(unsigned)-1};

    }
}

bool coord::operator==(const coord &rhs) const {
    return y == rhs.y &&
           x == rhs.x;
}

bool coord::operator!=(const coord &rhs) const {
    return !(rhs == *this);
}
