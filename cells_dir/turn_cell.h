//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_TURN_CELL_H
#define BLOCK_O_AUTOMATA_TURN_CELL_H

#include "cell.h"

class turn_cell : public cell{
public:

    turn_cell();


    turn_cell(direction turnDirection);

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

    friend std::ostream &operator<<(std::ostream &out, const turn_cell &ref);

    void rotateRight() noexcept override;

    void output_fo_file(std::ostream &out) override;

protected:

    /// the direction that incoming cell will leave with
    direction turn_direction;

    type cell_type = Turn;
};


#endif //BLOCK_O_AUTOMATA_TURN_CELL_H
