#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "Game.h"

Game::Game(UserPlayer p_, GameObject b_): block(b_),  height(0), width(0), numDeadBlocks(0), numHit(0) {
    player = new UserPlayer(p_.getX(), p_.getY(), p_.getSymbol());
};
Game::~Game() {
    delete player;
};

void Game::printGameBoard() {
    for (int i = 0; i < gameboard.size(); i++) {
        cout << endl;
        for (int j = 0; j < gameboard[i].size(); j++) {
            cout<<gameboard[i][j] -> getSymbol();
        }
    }
    cout << endl;
};
void Game::playGame() {
    int threshold = 80;
    char userInput = 'w';
    
    cout<<"Welcome to the game. There are "<<numDeadBlocks<<" hidden deadly blocks."<<endl;
    cout<<"Try to reach the bottom right corner without being hit by "<<threshold<<"%% of them :)"<<endl;
    
    while (userInput != 'q') {
        printGameBoard();
        cout<<"Enter a move (wasd) or (q) to quit: ";
        userInput = _getch();
        cout<<endl;

        gameboard[player->getY()][player->getX()] = &block;
        bool status = player->move(userInput, width, height);

        if (!status) {
            if (userInput != 'w' && userInput != 's' && userInput != 'a' && userInput != 'd') {
                cout<<"invalid move."<<endl;
            } else {
                cout<<"cannot move in that direction"<<endl;
            }
        }

        gameboard[player->getY()][player->getX()] = player;        
    }

    system("pause");
};
void Game::readBoardFromCSV(string filename) {
    fstream fin;
    fin.open(filename, ios::in);

    vector<GameObject*> row;
    string line, word;
    int rowCount = 0, columnCount = 0;

    while (getline(fin, line)) {
        row.clear();
        columnCount = 0;
        stringstream s(line);

        while (getline(s, word, ',')) {
            if (word == "X") {
                row.push_back(player);
            } else if (word == "O") {
                deadBlockLocation.push_back({columnCount, rowCount});
                numDeadBlocks++;
                row.push_back(&block);
            } else {
                row.push_back(&block);
            }
            columnCount++;
        }

        gameboard.push_back(row);
        rowCount++;
    }
    fin.close();

    width = columnCount;
    height = rowCount;
};