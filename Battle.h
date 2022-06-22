#ifndef PJC_11C_SUMMER22_ITN_BATTLE_H
#define PJC_11C_SUMMER22_ITN_BATTLE_H

#include "Player.h"
#include "Enemy.h"

class Battle
{
public:

    Battle();
    virtual ~Battle();
    int flagDifficulty = 0;
    int roundCounter = 1;

    inline const int& getFlagDifficulty() const
    {
        return this -> flagDifficulty;
    };

    void enemyEncounter(vector<Creature>& playerCreatures,
                        vector<Creature>& enemyCreatures);

    int natureTypeCheck(Creature &a, Creature &b);
};


#endif //PJC_11C_SUMMER22_ITN_BATTLE_H