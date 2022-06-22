#include "Player.h"

/*
 * @brief An empty default constructor of class Player
 *
 */
Player::Player()
{}

/*
 * @brief An empty default destructor of class Player
 *
 */
Player::~Player()
{}

/*
 * @brief A functions which allows the player to select desired creatures
 *        from a container containing all possible creatures
 *
 * @details This function creates a new container of type std::vector,
 *          containing objects of type Creature, possible of holding
 *          6 elements. This function includes implementation of a player
 *          inputting an incorrect choice, at which an error message is
 *          presented, along with asking the player to input a correct
 *          choice. The elements are added into the vector during run-time.
 *          Each element added increments the size of the vector by 1.
 *
 * @returns Returns a container of type std::vector containing objects of
 *          type <Creature>, playerCreatures
 */
vector<Creature> Player::creatureSelection()
{
    Creature crea;
    crea.setUp();

    Creature::printVec(crea.creaturesVec);

    int counter = 0;

    while (playerCreatures.size() < 6)
    {
        int tmp;

        cout <<   "Select your characters:"   << endl;
        cout << "Enter Number from 1 to 14 ("
             << 6 - counter << " spots left)" << endl;
        cin  >> tmp;

        if (tmp < 1 || tmp > 14)
        {
            cout <<            "Invalid Choice."         << endl;
            cout << "Please enter a number from 1 to 14\n" << endl;
            continue;
        }

        playerCreatures.emplace_back(crea.creaturesVec.at(tmp - 1));
        counter++;

    }
    cout << "\n" << endl;
    cout << "Team selected.\n" << endl;
    Creature::printVec(playerCreatures);

    return playerCreatures;
}