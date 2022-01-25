#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

Player::Player(){
    playerName = "";
    frustrationLevel = 0;
    dogeCoin = 200;
    computer = 1;
    IPL = 1;
    VPN = 1;
    antiVirus = 0;
    compMaintLvl = 100;
    myCompParts = {0, 0, 0, 0, 0, 0, 1}; //CPU / GPU / PS / CC / IC / KM / PreComp
    compVirus = 0;
}

string Player::getPlayerName(){
    return playerName;
}
void Player::setPlayerName(string playerNameIn){
    playerName = playerNameIn;
}

int Player::getFrustrationLevel(){
    return frustrationLevel;
}
void Player::setFrustrationLevel(int frustrationLevelIn){
    frustrationLevel = frustrationLevelIn;
}

double Player::getDogeCoin(){
    return dogeCoin;
}
void Player::setDogeCoin(double dogeCoinIn){
    dogeCoin = dogeCoinIn;
}

int Player::getComputer(){
    return computer;
}
void Player::setComputer(int computerIn){
    computer = computerIn;
}

int Player::getIPL(){
    return IPL;
}
void Player::setIPL(int IPLIn){
    IPL = IPLIn;
}

int Player::getVPN(){
    return VPN;
}
void Player::setVPN(int VPNIn){
    VPN = VPNIn;
}

int Player::getAntiVirus(){
    return antiVirus;
}
void Player::setAntiVirus(int antiVirusIn){
    antiVirus = antiVirusIn;
}

int Player::getCompMaintLvl(){
    return compMaintLvl;
}
void Player::setCompMaintLvl(int compMaintLvlIn){
    compMaintLvl = compMaintLvlIn;
}

int Player::getMyCompParts(int vecPosIn){
    return myCompParts[vecPosIn];
}
void Player::setMyCompParts(int vecPosIn, int newNumIn){
    myCompParts[vecPosIn] += newNumIn;
}

void Player::displayMyCompParts(){
    cout << "\t *My Inventory*" << endl;
    cout << "1. CPU: " << myCompParts[0] << endl;
    cout << "2. GPU: " << myCompParts[1] << endl;
    cout << "3. Power Supply Unit: " << myCompParts[2] << endl;
    cout << "4. Computer Case: " << myCompParts[3] << endl;
    cout << "5. Internet Card: " << myCompParts[4] << endl;
    cout << "6. Keyboard and Mouse: " << myCompParts[5] << endl;
    cout << "7. Premade Computer: " << myCompParts[6] << endl;
}

int Player::getCompVirus(){
    return compVirus;
}
void Player::setCompVirus(int compVirusIn){
    compVirus += compVirusIn;
}

