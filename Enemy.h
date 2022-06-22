#ifndef PJC_11C_SUMMER22_ITN_ENEMY_H
#define PJC_11C_SUMMER22_ITN_ENEMY_H

#include "Creature.h"

class Enemy
{
public:

    Enemy();
    virtual ~Enemy();
    vector<Creature> enemyCreatureSelection();
    vector<Creature> enemyCreatures;

    inline const vector<Creature>& getEnemyCreatures() const
    {
        return this -> enemyCreatures;
    };
};


#endif //PJC_11C_SUMMER22_ITN_ENEMY_H