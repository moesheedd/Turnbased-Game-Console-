#ifndef PJC_11C_SUMMER22_ITN_PLAYER_H
#define PJC_11C_SUMMER22_ITN_PLAYER_H

#include "Creature.h"

class Player
{
public:

    Player();
    virtual ~Player();
    vector<Creature> creatureSelection();
    vector<Creature> playerCreatures;

    inline const vector<Creature>& getPlayerCreatures() const
    {
        return this -> playerCreatures;
    };
};

#endif //PJC_11C_SUMMER22_ITN_PLAYER_H