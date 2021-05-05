//
// Created by pc on 05.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_LEVEL_INFO_H
#define BLOCK_O_AUTOMATA_LEVEL_INFO_H

// todo figure out if we should move all level creation stuff to this class and in board use level as level
//
class level_info{


public:
    int width;
    int height;
protected:
    std::strig author;
    unsigned best_score;
    std::vector<cell*> level;
};


#endif //BLOCK_O_AUTOMATA_LEVEL_INFO_H
