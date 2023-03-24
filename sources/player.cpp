#include "player.hpp"
#include "iostream"
using namespace std;

Player::Player(){
    
}
Player::Player(string player_Name)
{
    this->player_Name = player_Name;
}

int Player::cardesTaken()
{
    return 0;
}

int Player::stacksize()
{
    return 0;
}