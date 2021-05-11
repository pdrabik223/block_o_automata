//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_SPAWN_CELL_H
#define BLOCK_O_AUTOMATA_SPAWN_CELL_H


#include "cell.h"

class spawn_cell: public cell {
public:

    spawn_cell( );

    spawn_cell(int lives,  direction spawnDirection);

    spawn_cell( direction spawnDirection);

    spawn_cell &operator=(const spawn_cell &other) = default;

    void show_in_console_unicode() override;

    icon get_unicode() override;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int w) override;

    bool operator==(const type &rhs) const override;

    bool operator!=(const type &rhs) const override;

    direction getSpawnDirection() const;

    void setSpawnDirection(direction spawnDirection);

    type getCellType() const override;

    friend std::ostream &operator<<(std::ostream &out, const spawn_cell &ref);

    friend std::istream &operator>>(std::istream &in,  spawn_cell &ref);

    unsigned int getLives() const;

    void setLives(unsigned int lives);

protected:
    /// how many more cells can be spawned
    unsigned lives;
    /// the place where cell be spawned
    direction spawn_direction;

    type cell_type = t_spawn;
};


#endif //BLOCK_O_AUTOMATA_SPAWN_CELL_H
