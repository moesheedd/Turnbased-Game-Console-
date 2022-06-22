#include "Battle.h"

/*
 * @brief An empty default constructor for class Battle.
 */
Battle::Battle()
{}

/*
 * @brief An empty default destructor for class Battle.
 */
Battle::~Battle()
{}

/*
 * @brief A function which initiates a battle between Player Creatures
 *        and Enemy Creatures.
 *
 * @param References to two containers of type std::vector, containing objects
 *        of type Creature, playerCreatures and enemyCreatures.
 *
 * @return Returns void
 */
void Battle::enemyEncounter(vector<Creature> &playerCreatures,
                            vector<Creature> &enemyCreatures)
{
    bool playerTurn = true;
    int choice = 0;
    Creature activeCreature = playerCreatures.at(0);
    Creature activeEnemyCreature = enemyCreatures.at(0);

    //End conditions
    bool playerDefeated = false;
    bool enemyDefeated = false;

    //Battle variables
    int damage;
    int gainEXP;
    int playerTurnCounter = 0;

    cout << "Round " << roundCounter << "\n" << endl;

    while (!playerDefeated && !enemyDefeated)
    {
        if (playerTurn && !playerDefeated)
        {
            cout << "Your turn \n" << endl;

            cout << "Active creature: "
                 << activeCreature.getAsString() << endl;

            cout << "You are attacking: "
                 << activeEnemyCreature.getAsString() << "\n" << endl;

            cout <<           "Battle Menu"        << endl;
            cout <<           "1. Attack."         << endl;
            cout <<       "2. Special Attack. "
                     "(Can be used every 3 turns)" << endl;
            cout <<  "3. Evolve active creature."  << endl;
            cout << "4. Change active creature.\n" << endl;

            cout << "Enter a number from 1 to 4" << endl;

            cin >> choice;

            if (choice < 1 || choice > 4)
            {
                cout <<             "Invalid Choice."         << endl;
                cout << "Please enter a number from 1 to 4 \n" << endl;
                continue;
            }

            switch (choice)
            {
                case 1:
                    damage = natureTypeCheck
                            (activeCreature, activeEnemyCreature)
                            + activeCreature.getStrength()
                            - activeEnemyCreature.getDexterity();
                    activeEnemyCreature.takeDamage(damage);

                    cout << "You have hit "
                         << activeEnemyCreature.getName() <<  " for "
                         << damage << " !\n" << endl;

                    if (!activeEnemyCreature.isAlive())
                    {
                        cout << activeEnemyCreature.getName()
                             << " defeated!\n" << endl;

                        gainEXP = activeEnemyCreature.getExp();
                        activeCreature.gainEXP(gainEXP);

                        cout << activeCreature.getName() << " gained "
                             << gainEXP << " exp!\n" << endl;

                        for (int i = 0; i < enemyCreatures.size(); i++)
                        {
                            if (activeEnemyCreature.getID()
                                == enemyCreatures.at(i).getID())
                            {
                                enemyCreatures.erase
                                (enemyCreatures.begin() + i);
                            }
                        }
                        cout << "Remaining enemies: " << endl;
                        Creature::printVec(enemyCreatures);

                        if (enemyCreatures.empty())
                        {
                            enemyDefeated = true;
                        }
                        activeEnemyCreature = enemyCreatures.at(0);
                    }
                    break;

                case 2:
                    if (playerTurnCounter % 3 == 0 && playerTurnCounter != 0)
                    {
                        damage = activeCreature.getSpecialDamage()
                                - activeEnemyCreature.getDexterity()
                                + activeCreature.getStrength();
                        activeEnemyCreature.takeDamage(damage);
                    }
                    else
                    {
                        cout << "Can only be used every 3 turns." << endl;
                        break;
                    }

                    cout << "You have hit " << activeEnemyCreature.getName()
                         << " with '" << activeCreature.getSpecial()
                         << "' for " << damage << " !\n" << endl;

                    if (!activeEnemyCreature.isAlive())
                    {
                        cout << activeEnemyCreature.getName()
                             << " defeated!\n" << endl;

                        gainEXP = activeEnemyCreature.getExp();
                        activeCreature.gainEXP(gainEXP);

                        cout << activeCreature.getName() << " gained "
                             << gainEXP << " exp!\n" << endl;

                        for (int i = 0; i < enemyCreatures.size(); i++)
                        {
                            if (activeEnemyCreature.getID()
                                == enemyCreatures.at(i).getID())
                            {
                                enemyCreatures.erase
                                        (enemyCreatures.begin() + i);
                            }
                        }
                        cout << "Remaining enemies: " << endl;
                        Creature::printVec(enemyCreatures);

                        if (enemyCreatures.empty())
                        {
                            enemyDefeated = true;
                        }
                        activeEnemyCreature = enemyCreatures.at(0);
                    }
                    break;

                case 3:
                    activeCreature.levelUp();
                    break;

                case 4:

                    Creature::printVec(playerCreatures);
                    int temp;

                    cout << "Select your active creature" << endl;
                    cout << "Enter a number from 1 to 6\n"  << endl;
                    cout << "Currently active: "
                         << activeCreature.getAsString()  << endl;

                    cin >> temp;

                    if (temp < 1 || temp > playerCreatures.size())
                    {
                        cout << "Invalid Choice." << endl;
                        cout << "Please enter a number from 1 to "
                             << playerCreatures.size() << endl;
                        continue;
                    }
                        activeCreature = playerCreatures.at(temp - 1);

                    break;
            }
            //End turn
            playerTurn = false;
        }

        else if (!playerTurn && !playerDefeated && !enemyDefeated)
        {
            cout << "Enemy turn\n" <<  endl;
            damage = natureTypeCheck
                    (activeEnemyCreature, activeCreature)
                    + activeEnemyCreature.getStrength()
                    - activeCreature.getDexterity();

            cout << activeEnemyCreature.getName() << " has hit "
                 << activeCreature.getName() << " for ";

            switch (flagDifficulty)
            {
                case 1:
                    activeCreature.takeDamage(damage);
                    cout << damage << " !!" << endl;
                    break;

                case 2:
                    activeCreature.takeDamage(damage + 3);
                    cout << damage + 3 << " !!" << endl;
                    break;

                case 3:
                    activeCreature.takeDamage(damage + 5);
                    cout << damage + 5 << " !!" << endl;
                    break;
            }

            if (!activeCreature.isAlive())
            {
                cout << activeCreature.getName()
                     << " has fallen !\n" << endl;

                for (int i = 0; i < playerCreatures.size(); i++)
                {
                    if (activeCreature.getID() ==
                        playerCreatures.at(i).getID())
                    {
                        playerCreatures.erase
                                (playerCreatures.begin() + i);
                    }
                }
                cout << "Remaining player creatures: " << endl;
                Creature::printVec(playerCreatures);

                if (playerCreatures.empty())
                {
                    playerDefeated = true;
                }
                activeCreature = playerCreatures.at(0);
            }
            playerTurn = true;
            playerTurnCounter++;
        }
        //Conditions
        if (playerCreatures.empty())
        {
            playerDefeated = true;
            cout << "You lose..\n" << endl;
        }
        else if (enemyCreatures.empty())
        {
            enemyDefeated = true;
            cout << "Round Won!! \n" << endl;
        }
    }
    roundCounter++;
}
/*
 * @brief A function which checks the natureType of two creatures.
 *
 * @param References to two objects of type Creature, a and b.
 *
 * @return Returns the updates value of damage for attacking creature (a).
 *         A variable of type int.
 */
int Battle::natureTypeCheck(Creature &a, Creature &b)
{
    if (a.getNatureType() == "Water")
    {
        if (b.getNatureType() == "Water")
        {
            return a.getDamage() - 3;
        }
        if (b.getNatureType() == "Earth" || "Fire")
        {
            return a.getDamage() + 3;
        }
    }

    if (a.getNatureType() == "Earth")
    {
        if (b.getNatureType() == "Air")
        {
            return a.getDamage() - 3;
        }
        if (b.getNatureType() == "Fire" || "Ice" || "Steel")
        {
            return a.getDamage() + 3;
        }
    }

    if (a.getNatureType() == "Air")
    {
        if (b.getNatureType() == "Earth" || "Steel")
        {
            return a.getDamage() - 3;
        }
        else
            if (b.getNatureType() == "Ice")
        {
            return a.getDamage() + 3;
        }
    }

    if (a.getNatureType() == "Fire")
    {
        if (b.getNatureType() == "Water" || "Earth")
        {
            return a.getDamage() - 3;
        }
        if (b.getNatureType() == "Ice" || "Steel")
        {
            return a.getDamage() + 3;
        }
    }

    if (a.getNatureType() == "Ice")
    {
        if (b.getNatureType() == "Water" || "Fire" || "Ice")
        {
            return a.getDamage() - 3;
        }
        if (b.getNatureType() == "Earth")
        {
            return a.getDamage() + 3;
        }
    }

    if (a.getNatureType() == "Steel")
    {
        if (b.getNatureType() == "Fire" || "Steel")
        {
            return a.getDamage() - 3;
        }
        if (b.getNatureType() == "Water" || "Air")
        {
            return a.getDamage() + 3;
        }
    }

    else
        return a.getDamage();
}