//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_MOVE_CELL_H
#define BLOCK_O_AUTOMATA_MOVE_CELL_H

#include "cell.h"

/// can move only in the move direction
class move_cell : public cell {
public:
    move_cell();

    move_cell(direction moveDirection);

    void show_in_console_unicode() override;

    move_cell &operator=(const move_cell &other) = default;

    icon get_unicode() override;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    bool operator==(const type &rhs) const override;

    bool operator!=(const type &rhs) const override;

    void setMoveDirection(direction moveDirection);

    direction getMoveDirection() const;

    type getCellType() const override;

    friend std::ostream &operator<<(std::ostream &out, const move_cell &ref);

    void rotateRight()  noexcept override;


protected:
    direction move_direction;

  const   type cell_type = Move;

};


#endif //BLOCK_O_AUTOMATA_MOVE_CELL_H
