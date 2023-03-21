#include "player.hpp"
#include "iostream"
using namespace std;


Player::Player(string player_Name)
{
    this->player_Name = player_Name;
}

int Player::cardesTaken()
{
    return 1;
}

int Player::stacksize()
{
    return 1;
}