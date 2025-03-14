#include <stdio.h>
#include "Game.h"

int main() {
    UserPlayer player = UserPlayer(0, 0, 'X');
    GameObject block = GameObject('-');

    Game* game = new Game(player, block);

    game->readBoardFromCSV("gameboard.csv");
    game->playGame();

    delete game;
    game = nullptr;

    // Pause to keep the console open
    system("pause");
}