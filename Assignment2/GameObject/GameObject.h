#include <stdio.h>
using namespace std;

class GameObject {
    protected:
        char symbol;
    public:
        GameObject(char symbol_);
        ~GameObject();

        void setSymbol(char s);
        char getSymbol();
};