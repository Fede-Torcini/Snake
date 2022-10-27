#include "Game.h"

using namespace snakegame;

int main()
{
    Game game;

    // Start the game loop
    while (game.running())
    {
        game.update();

        game.render();
    }
}