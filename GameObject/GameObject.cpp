#include "GameObject.h"

GameObject::GameObject(char symbol_): symbol(symbol_) {};
GameObject::GameObject() {};
GameObject::~GameObject() {};

void GameObject::setSymbol(char s) {
    symbol = s;
};
char GameObject::getSymbol() {
    return symbol;
};
