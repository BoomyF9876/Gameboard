#include <stdio.h>
#include <vector>
#include "GameObject/UserPlayer.h"
using namespace std;

class Game {
    private:
        int width, height, numDeadBlocks, numHit;
        GameObject block;
        vector<GameObject*> gameboard;
        vector<vector<int>> deadBlockLocation;
        UserPlayer* player;

    public:
        Game(UserPlayer p_, GameObject b_);
        ~Game();

        void printGameBoard();
        void playGame();
};
