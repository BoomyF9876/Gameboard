#include "Game.h"

Game::Game(UserPlayer p_, GameObject b_) {
    player = new UserPlayer(p_.getX(), p_.getY(), p_.getSymbol());
    block = b_;
};
Game::~Game() {
    delete player;
};

void Game::printGameBoard() {

};
void Game::playGame() {
    
};