#include "GameObject.h"

class UserPlayer: public GameObject {
    private:
        int x,y;
    public:
        UserPlayer(int x_, int y_, char s = 'X');
        ~UserPlayer();

        void setX(int x_);
        void setY(int y_);
        int getX();
        int getY();

        bool move(char direction, int maxWidth, int maxHeight);
};