#include <iostream>
#include "Player.h"
#include "BestBuy.h"
#include "Map.h"
#include "Hacker.h"
#include "Game.h"

using namespace std;

int main(){
    Game game;
    //Beginning of game and best buy
    game.start();

    //Function thats going to loop until all hackers are cleared in SR1, then it will move to S2
    game.serverRoom1();

    //Function thats going to loop until all hackers are cleared in SR2, then it will move to S3
    game.serverRoom2();

    //Function thats going to loop until all hackers are cleared in SR3, then it will move to S4
    game.serverRoom3();

    //Function thats going to loop until all hackers are cleared in SR4, then it will move to S5
    game.serverRoom4();

    //Function thats going to loop until all hackers are cleared in SR5, then it will end game
    game.serverRoom5();

    //End win condition
    game.end();
}