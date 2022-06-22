#include "Enemy.h"

/*
 * @brief An empty default constructor for class Enemy
 */
Enemy::Enemy()
{}

/*
 * @brief An empty default deconstructor for class Enemy
 */
Enemy::~Enemy()
{}

/*
 * @brief A function inserting objects of type creature at random to a
 *        container of type stD::vector
 *
 * @return Returns a container of type std::vector, containing objects
 *         of type creature
 */
vector<Creature> Enemy::enemyCreatureSelection()
{
    Creature crea;
    crea.setUp();

    while (enemyCreatures.size() < 4)
    {
        int random = rand() % crea.creaturesVec.size();
        enemyCreatures.emplace_back(crea.creaturesVec[random]);
    }

    cout << "Enemy team: \n" << endl;
    Creature::printVec(enemyCreatures);

    return enemyCreatures;
}