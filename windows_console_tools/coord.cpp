//
// Created by studio25 on 26.05.2021.
//

#include "coord.h"
unsigned Coord::ToUint(unsigned int w) const {
    assert(y_ < w);
    assert(w != 0);
    return x_ * w + y_;
}

void Coord::MoveBy(Direction dir) {
    switch (dir) {
        case LEFT:
            assert(y_ >= 0);
            --y_;
            break;
        case RIGHT:
            ++y_;
            break;
        case UP:
            assert(x_ >= 0);
            --x_;
            break;
        case DOWN:
            ++x_;
            break;
        default:
            assert(false);
            break;
    }


}

unsigned Coord::Reverse(Direction dir, unsigned int w) const {
    assert(y_ < w);
    assert(w != 0);

    switch (dir) {
        case RIGHT:
            assert(y_ >= 0);
            return x_ * w + y_ - 1;

        case LEFT:
            return x_ * w + y_ + 1;

        case DOWN:
            assert(x_ >= 0);
            return (x_ - 1) * w + y_;

        case UP:
            return (x_ + 1) * w + y_;

        default:
            assert(false);
            return -1;

    }
}

unsigned Coord::Go(Direction dir, unsigned int w) const {
    assert(y_ <= w);
    assert(w != 0);

    switch (dir) {
        case LEFT:
            assert(y_ >= 0);
            return x_ * w + y_ - 1;

        case RIGHT:
            return x_ * w + y_ + 1;

        case UP:
            assert(x_ >= 0);
            return (x_ - 1) * w + y_;

        case DOWN:
            return (x_ + 1) * w + y_;

        default:
            assert(false);
            return -1;
    }
}

Coord Coord::Reverse(Direction dir) const {
    switch (dir) {
        case RIGHT:
            assert(y_ >= 0);
            return {x_, y_ - 1};

        case LEFT:
            return {x_, y_ + 1};

        case DOWN:
            assert(x_ >= 0);
            return {x_ - 1, y_};

        case UP:
            return {x_ + 1, y_};

        default:
            assert(false);
            return {(unsigned)-1,(unsigned)-1};

    }
}

Coord Coord::Go(Direction dir) const {
    switch (dir) {
        case LEFT:
            assert(y_ >= 0);
            return {x_, y_ - 1};

        case RIGHT:
            return {x_, y_ + 1};

        case UP:
            assert(x_ >= 0);
            return {x_ - 1, y_};

        case DOWN:
            return {x_ + 1, y_};

        default:
            assert(false);
            return {(unsigned)-1,(unsigned)-1};

    }
}

bool Coord::operator==(const Coord &rhs) const {
    return y_ == rhs.y_ && x_ == rhs.x_;
}

bool Coord::operator!=(const Coord &rhs) const {
    return !(rhs == *this);
}



