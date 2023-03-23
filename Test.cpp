#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"

using namespace std;

TEST_CASE("check_intial_players")
{
    CHECK_NOTHROW(Player p2("Yuval"));
    CHECK_THROWS_AS(Player p2(""), invalid_argument); //going to demand a name length of atleast 2 characters
    Player p1("Yuval1");
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p1.stacksize());
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
}

TEST_CASE("testing_Game_constructor")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    CHECK_NOTHROW(Game game(p1,p2));
    Player p3("Yuval3");
    Game game(p1,p2);
    CHECK_THROWS_AS(Game game2(p1,p3), invalid_argument); // p1 can be only part of one game at a time
    game.playAll();
    CHECK_NOTHROW(Game game2(p1,p3));
    Game game2(p1,p3);
    //check that p1's stats reset
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
}

TEST_CASE("test_shuffle")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    Game game(p1,p2);
    CHECK(p1.stacksize() + p2.stacksize() == 52);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("test_turn")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize() != 26);
    CHECK(p2.stacksize() != 26);
}

TEST_CASE("test_cards_taken")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    Game game(p1,p2);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    game.playTurn();
    bool card_taken = false;
    if(p1.cardesTaken() > 0 || p2.cardesTaken() > 0)
        card_taken = true;
    CHECK(card_taken == true);
}

TEST_CASE("test_game_end")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    Game game(p1,p2);
    game.playAll();
    bool player_won = false;
    if(p1.stacksize() == 0 || p2.stacksize() == 0)
        player_won = true;
    CHECK(player_won == true);
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("test_game_functions")
{
    Player p1("Yuval1");
    Player p2("Yuval2");
    Game game(p1,p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

