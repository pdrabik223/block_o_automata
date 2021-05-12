//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EMPTY_CELL_H
#define BLOCK_O_AUTOMATA_EMPTY_CELL_H
#include "cell.h"

class empty_cell: public cell{

public:
    empty_cell();
    empty_cell( bool locked);

    type getCellType() const override;

    void show_in_console_unicode() override;

    empty_cell &operator=(const empty_cell &other)  = default;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    icon get_unicode() override;

    bool isLocked() const;

    void setLocked(bool locked);

    bool operator==(const type& rhs) const override;

    bool operator!=(const type &rhs) const override;

    friend std::ostream &operator<<(std::ostream &out, const empty_cell &ref);

    friend std::istream &operator>>(std::istream &in,  empty_cell &ref);

protected:
    /// can player put cells in place this one
    bool locked;
    const  type cell_type = Empty;
};


#endif //BLOCK_O_AUTOMATA_EMPTY_CELL_H
