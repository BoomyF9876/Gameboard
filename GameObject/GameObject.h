#include <stdio.h>
using namespace std;

class GameObject {
    protected:
        char symbol;
    public:
        GameObject();
        GameObject(char symbol_);
        ~GameObject();

        void setSymbol(char s);
        char getSymbol();
};