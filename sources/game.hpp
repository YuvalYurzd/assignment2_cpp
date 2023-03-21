#ifndef header
#define header
#include "iostream"
#include "player.hpp"
using namespace std;

class Game {
private:
    Player p1;
    Player p2;

public:
    Game(Player p1, Player p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};
#endif
