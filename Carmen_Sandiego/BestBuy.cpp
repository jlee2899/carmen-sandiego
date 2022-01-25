#include <iostream>
#include "BestBuy.h"

using namespace std;

BestBuy::BestBuy(){
    bestBuyName = "Best Buy";
    CPU = 10;
    GPU = 20;
    powerSupply = 5;
    computerCase = 15;
    internetCard = 5;
    keyboardMouse = 10;
    preComputer = 100;
    antiVirus = 10;
    VPN = 20;
    iP2 = 10;
    iP3 = 25;
    iP4 = 40;
    iP5 = 50;
    serverRoom = 0;
}

string BestBuy::getBestBuyName(){
    return bestBuyName;
}
void BestBuy::setBestBuyName(string bestBuyNameIn){
    bestBuyName = bestBuyNameIn;
}

double BestBuy::getCPUCost(){
    return CPU;
}
void BestBuy::setCPUCost(double CPUCostIn){
    CPU = CPUCostIn;
}

double BestBuy::getGPUCost(){
    return GPU;
}
void BestBuy::setGPUCost(double GPUCostIn){
    GPU = GPUCostIn;
}

double BestBuy::getPowerSupplyCost(){
    return powerSupply;
}
void BestBuy::setPowerSupplyCost(double powerSupplyCostIn){
    powerSupply = powerSupplyCostIn;
}

double BestBuy::getComputerCaseCost(){
    return computerCase;
}
void BestBuy::setComputerCaseCost(double computerCaseCostIn){
    computerCase = computerCaseCostIn;
}

double BestBuy::getInternetCardCost(){
    return internetCard;
}
void BestBuy::setInternetCardCost(double internetCardCostIn){
    internetCard = internetCardCostIn;
}

double BestBuy::getKeyboardMouseCost(){
    return keyboardMouse;
}
void BestBuy::setKeyboardMouseCost(double keyboardMouseCostIn){
    keyboardMouse = keyboardMouseCostIn;
}

double BestBuy::getPreComputerCost(){
    return preComputer;
}
void BestBuy::setPreComputerCost(double preComputerCostIn){
    preComputer = preComputerCostIn;
}

double BestBuy::getAntiVirusCost(){
    return antiVirus;
}
void BestBuy::setAntiVirusCost(double antiVirusCostIn){
    antiVirus = antiVirusCostIn;
}

double BestBuy::getVPNCost(){
    return VPN;
}
void BestBuy::setVPNCost(double VPNCostIn){
    VPN = VPNCostIn;
}

double BestBuy::getIP2Cost(){
    return iP2;
}
void BestBuy::setIP2Cost(double iP2CostIn){
    iP2 = iP2CostIn;
}

double BestBuy::getIP3Cost(){
    return iP3;
}
void BestBuy::setIP3Cost(double iP3CostIn){
    iP3 = iP3CostIn;
}

double BestBuy::getIP4Cost(){
    return iP4;
}
void BestBuy::setIP4Cost(double iP4CostIn){
    iP4 = iP4CostIn;
}

double BestBuy::getIP5Cost(){
    return iP5;
}
void BestBuy::setIP5Cost(double iP5CostIn){
    iP5 = iP5CostIn;
}

int BestBuy::getServerRoom(){
    return serverRoom;
}
void BestBuy::setServerRoom(int serverRoomIn){
    serverRoom = serverRoomIn;
}

void BestBuy::turingRoom(){
    bestBuyName = "Turing Room Best Buy";
    serverRoom = 1;
    CPU = 10;
    GPU = 20;
    powerSupply = 5;
    computerCase = 15;
    internetCard = 5;
    keyboardMouse = 10;
    preComputer = 100;
    antiVirus = 10;
    VPN = 20;
    iP2 = 10;
    iP3 = 25;
    iP4 = 40;
    iP5 = 50;
}

void BestBuy::ellisRoom(){
    bestBuyName = "Ellis Room Best Buy";
    serverRoom = 2;
    CPU = 11;
    GPU = 22;
    powerSupply = 5.5;
    computerCase = 16.5;
    internetCard = 5.5;
    keyboardMouse = 11;
    preComputer = 110;
    antiVirus = 11;
    VPN = 22;
    iP2 = 11;
    iP3 = 27.5;
    iP4 = 44;
    iP5 = 55;
}

void BestBuy::johnsonRoom(){
    bestBuyName = "Johnson Room Best Buy";
    serverRoom = 3;
    CPU = 12;
    GPU = 24;
    powerSupply = 6;
    computerCase = 18;
    internetCard = 6;
    keyboardMouse = 12;
    preComputer = 120;
    antiVirus = 12;
    VPN = 24;
    iP2 = 12;
    iP3 = 30;
    iP4 = 48;
    iP5 = 60;
}

void BestBuy::hopperRoom(){
    bestBuyName = "Hopper Room Best Buy";
    serverRoom = 4;
    CPU = 12.5;
    GPU = 25;
    powerSupply = 6.25;
    computerCase = 18.75;
    internetCard = 6.25;
    keyboardMouse = 12.5;
    preComputer = 125;
    antiVirus = 12.5;
    VPN = 25;
    iP2 = 12.5;
    iP3 = 31.25;
    iP4 = 50;
    iP5 = 62.5;
}

void BestBuy::mooreRoom(){
    bestBuyName = "Moore Room Best Buy";
    serverRoom = 5;
    CPU = 13;
    GPU = 26;
    powerSupply = 6.5;
    computerCase = 19.5;
    internetCard = 6.5;
    keyboardMouse = 13;
    preComputer = 130;
    antiVirus = 13;
    VPN = 26;
    iP2 = 13;
    iP3 = 32.5;
    iP4 = 52;
    iP5 = 65;
}
