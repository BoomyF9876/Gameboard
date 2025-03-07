#include <stdio.h>
#include "Game/Game.h"
using namespace std;

int main() {
    UserPlayer player = UserPlayer(0, 0, 'X');
    GameObject block = GameObject('-');

    Game* game = new Game(player, block);
    game->readBoardFromCSV("gameboard.csv");

    game->playGame();
}