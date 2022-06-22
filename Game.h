#ifndef PJC_11C_SUMMER22_ITN_GAME_H
#define PJC_11C_SUMMER22_ITN_GAME_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include "Creature.h"

using namespace std;

class Game
{
public:
    Game();
    virtual ~Game();

    //OPERATORS

    //FUNCTIONS
    void mainMenu();
    //void saveGame();
    //void loadGame();

    //ACCESSORS

    /*
    * @brief
    * @param
    *
    */
    inline bool getPlaying() const
    {
        return this -> playing;
    };

    //MODIFIERS

private:
    int choice;
    bool playing;
};

//Save & Load game related
//string fileName;

#endif //PJC_11C_SUMMER22_ITN_GAME_H