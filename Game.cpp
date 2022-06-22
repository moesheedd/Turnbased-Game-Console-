#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

Game::Game()
{
    choice = 0;
    playing = true;
    //fileName = "CreaturesSaveGame.txt";
}

Game::~Game()
{}

//FUNCTIONS

/*
 * @brief A command that initiates the game's main menu
 *
 * @details A function that prints out the game's main menu, allowing
 *          the user to input their choice from the keyboard and based
 *          on that choice, input the chosen difficulty.
 */
void Game::mainMenu()
{
    cout <<       "MAIN MENU"      << endl;
    cout <<           ""           << endl;
    cout <<        "0: QUIT"       << endl;
    cout <<   "1: START NEW GAME"  << endl;
    cout << "2: SAVE CURRENT GAME" << endl;
    cout <<   "3: LOAD SAVE GAME"  << endl;

    cout << "" << endl;
    cout << "Choice: " << endl;

    cin >> choice;

    Creature cre;
    Player pla;
    Enemy nmy;
    Battle btl;

    switch(choice)
    {
        case 0:
            cout << "YOU QUIT." << endl;
            playing = false;
            break;

        case 1:
            cout << "Please choose difficulty level: " << endl;
            cout <<           "1. Easy"                << endl;
            cout <<          "2. Medium"               << endl;
            cout <<           "3. Hard"                << endl;

            cout << "" << endl;
            cout << "Difficulty: " << endl;

            cin >> btl.flagDifficulty;

            switch(btl.getFlagDifficulty())
            {
                case 1:
                    cout << "Difficulty chosen is Easy.\n" << endl;
                    pla.creatureSelection();
                    nmy.enemyCreatureSelection();
                    while (btl.roundCounter < 6)
                    {
                        btl.enemyEncounter(pla.playerCreatures,
                                           nmy.enemyCreatures);
                    }
                    break;

                case 2:
                    cout << "Difficulty chosen is Medium.\n" << endl;
                    pla.creatureSelection();
                    nmy.enemyCreatureSelection();
                    while (btl.roundCounter < 6)
                    {
                        btl.enemyEncounter(pla.playerCreatures,
                                           nmy.enemyCreatures);
                    }
                    break;

                case 3:
                    cout << "Difficulty chosen is Hard.\n" << endl;
                    pla.creatureSelection();
                    nmy.enemyCreatureSelection();
                    while (btl.roundCounter < 6)
                    {
                        btl.enemyEncounter(pla.playerCreatures,
                                           nmy.enemyCreatures);
                    }
                    break;

                default:
                    cout << "INCORRECT CHOICE!" << endl;
                    break;
            }
            break;

        case 2:
            //saveGame();
            break;

        case 3:
            //loadGame();
            break;

        default:
            cout << "INCORRECT CHOICE!" << endl;
            break;
    }
}

/*
void Game::saveGame()
{
    Player p;
    ofstream outfile(fileName);

    if (outfile.is_open())
    {
        for (size_t i = 0; i < p.getPlayerCreatures().size(); i++)
        {
            outfile << p.playerCreatures[i].getAsString() << endl;
        }
    }

    outfile.close();
};

void Game::loadGame()
{
    Player p;
    ifstream infile(fileName);

    p.playerCreatures.clear();

    std::string name = "NONE";
    int level = 1;
    int exp = 0;
    int expNext = 0;

    int health = 0;
    int strength = 0;
    int dexterity = 0;
    int damage = 0;
    int specialDamage = 0;
    std::string natureType = "NONE";
    std::string special = "NONE";

    int id = 999;

    std::string line = "";
    stringstream str;

    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            str.str(line);

            str >> name;
            str >> level;
            str >> expNext;

            str >> health;
            str >> strength;
            str >> dexterity;
            str >> damage;
            str >> specialDamage;
            str >> natureType;
            str >> special;

            str >> id;
        }
    }
    infile.close();

    if (p.playerCreatures.size() <= 0)
    {
        throw "Error! No creatures loaded or Empty file";
    }
}
*/