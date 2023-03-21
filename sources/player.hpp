#ifndef X
#define X
#include <iostream>

using namespace std;

class Player {
private:
    string player_Name;
public:
    Player();
    Player(string player_Name);
    int cardesTaken();
    int stacksize();
};
#endif


