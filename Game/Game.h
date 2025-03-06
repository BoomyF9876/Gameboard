#include <stdio.h>
#include <vector>
#include <string>
#include "GameObject/UserPlayer.h"
using namespace std;

class Game {
    private:
        int width, height, numDeadBlocks, numHit;
        GameObject block;
        UserPlayer* player;
        vector<vector<int>> deadBlockLocation;
        vector<vector<GameObject*>> gameboard;

    public:
        Game(UserPlayer p_, GameObject b_);
        ~Game();

        void printGameBoard();
        void playGame();
        void readBoardFromCSV(string filename);
};
