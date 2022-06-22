#include "Game.h"

int main()
{
    srand(time(nullptr));
    Game game;
    while(game.getPlaying())
    {
        game.mainMenu();
    }

    return 0;
}