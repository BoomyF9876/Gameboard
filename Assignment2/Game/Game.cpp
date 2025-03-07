#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include "Game.h"
using namespace std;

Game::Game(UserPlayer p_, GameObject b_): block(b_),  height(0), width(0), numDeadBlocks(0), numHit(0) {
    player = new UserPlayer(p_.getX(), p_.getY(), p_.getSymbol());
};
Game::~Game() {
    delete player;
};

void SetColor(int value) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void Game::printGameBoard() {
    for (int i = 0; i < gameboard.size(); i++) {
        cout << endl;
        for (int j = 0; j < gameboard[i].size(); j++) {
            char symbol = gameboard[i][j] -> getSymbol();
            if (symbol == 'X') {
                SetColor(4); // Red
            } else {
                SetColor(1); // Blue
            }
            cout<<symbol;
        }
    }
    SetColor(15); // White
    cout << endl;
};
void Game::playGame() {
    char userInput;
    
    cout<<"Welcome to the game. There are "<<numDeadBlocks<<" hidden deadly blocks."<<endl;
    cout<<"Try to reach the bottom right corner without being hit by 80%% of them :)"<<endl;
    
    while (player->getX() < width || player->getY() < height) {
        printGameBoard();
        cout<<"Enter a move (wasd) or (q) to quit: ";
        userInput = _getch(); // To take in user inputs without waiting for the enter key
        cout<<endl;

        gameboard[player->getY()][player->getX()] = &block;
        bool status = player->move(userInput, width, height);

        if (!status) {
            if (userInput != 'w' && userInput != 's' && userInput != 'a' && userInput != 'd' && userInput != 'q') {
                cout<<"invalid move."<<endl;
            } else if (userInput == 'q') {
                return;
            } else {
                cout<<"cannot move in that direction"<<endl;
            }
        } else {
            vector<int> playerPosition = {player->getX(), player->getY()};
            vector<vector<int>>::iterator index = find(deadBlockLocation.begin(), deadBlockLocation.end(), playerPosition);
            if (index != deadBlockLocation.end()) {
                numHit++;
                deadBlockLocation.erase(index);
                cout<<"You Got Hit! You have been hit "<<numHit<<" out of "<<numDeadBlocks<<endl;
            }
        }

        gameboard[player->getY()][player->getX()] = player;
    }

    printGameBoard();
    cout<<"You have reached the end!"<<endl;
    cout<<"You have been hit "<<numHit<<" out of "<<numDeadBlocks<<" throughout your journey."<<endl;
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
                player->setX(columnCount);
                player->setY(rowCount);

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

    // Minus one to indicate indices
    width = columnCount - 1;
    height = rowCount - 1;
};