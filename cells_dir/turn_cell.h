//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_TURN_CELL_H
#define BLOCK_O_AUTOMATA_TURN_CELL_H

#include "cell.h"

class turn_cell : public cell{
public:

    turn_cell();
    turn_cell(unsigned int rotationsLeft, direction turnDirection);

    turn_cell(direction turnDirection);

    void show_in_console_unicode() override;

    turn_cell &operator=(const turn_cell &other) = default;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    icon get_unicode() override;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    bool operator==(const type& rhs) const override;

    bool operator!=(const type &rhs) const override;

    type getCellType() const override;

    direction getTurnDirection() const;

    void setTurnDirection(direction turnDirection);

    unsigned int getRotationsLeft() const;

    void setRotationsLeft(unsigned int rotationsLeft);

    friend std::ostream &operator<<(std::ostream &out, const turn_cell &ref);

    friend std::istream &operator>>(std::istream &in,  turn_cell &ref);

protected:
    /// how many rotations can cell preform
    unsigned rotations_left;
    /// the direction that incoming cell will leave with
    direction turn_direction;

    type cell_type = t_turn;
};


#endif //BLOCK_O_AUTOMATA_TURN_CELL_H
