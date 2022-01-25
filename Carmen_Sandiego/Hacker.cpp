#include <iostream>
#include <vector>
#include "Hacker.h"

using namespace std;

Hacker::Hacker(){
    vecHackerNames = {"hansolo1337", "gandalf5000" , "tomato_cultivator20", "cheeto_dweller", "thejoker33", "furiosa_11", "woodythesheriff", "lizzathealien", "ironman123", "pizzaIsKnowledge", 
                        "bing_bong_2015", "num1_carmenfan77", "free_almonds", "uzer_1000", "twinkle_star99", "team-3dward-5evr", "crazyCatLady76", "numba_1programmer", "myNameisJeff", "treatYoSelf"};
    vecServerRoom = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5};
    progressLevel = 0;
}

string Hacker::getHackerName(int vecPosIn){
    return vecHackerNames[vecPosIn];
}
void Hacker::setHackerName(int vecPosIn, string hackerNameIn){
    vecHackerNames[vecPosIn] = hackerNameIn;
}

int Hacker::getServerRoom(int vecPosIn){
    return vecServerRoom[vecPosIn];
}
void Hacker::setServerRoom(int vecPosIn, int newNumIn){
    vecServerRoom[vecPosIn] = newNumIn;
}

int Hacker::getProgressLevel(){
    return progressLevel;
}
void Hacker::setProgressLevel(int progressLevelIn){
    progressLevel = progressLevelIn;
}

void Hacker::displayHackerNames(){
    for (int i = 0; i < vecHackerNames.size(); i++){
        cout << vecHackerNames[i] << endl;
    }
}

void sortHackerNR();
