#include "UserPlayer.h"

UserPlayer::UserPlayer(int x_, int y_, char s): x(x_), y(y_), GameObject(s) {};
UserPlayer::~UserPlayer() {};

void UserPlayer::setX(int x_) {
    x = x_;
};
void UserPlayer::setY(int y_) {
    y = y_;
};
int UserPlayer::getX() {
    return x;
};
int UserPlayer::getY() {
    return y;
};

bool UserPlayer::move(char direction, int maxWidth, int maxHeight) {
    if (direction != 'w' && direction != 's' && direction != 'a' && direction != 'd') return false;

    switch (direction) {
        case 'w':
            if (y <= 0) return false;
            y--;
            return true;
        case 's':
            if (y >= maxHeight - 1) return false;
            y++;
            return true;
        case 'a':
            if (x <= 0) return false;
            x--;
            return true;
        case 'd':
            if (x >= maxWidth - 1) return false;
            x++;
            return true;
        default:
            return false;
    }
};

