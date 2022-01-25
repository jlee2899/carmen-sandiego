#include <iostream>

using namespace std;

class BestBuy{
   private:
        string bestBuyName;
        double CPU;
        double GPU;
        double powerSupply;
        double computerCase;
        double internetCard;
        double keyboardMouse;
        double preComputer;
        double antiVirus;
        double VPN;
        double iP2;
        double iP3;
        double iP4;
        double iP5;
        int serverRoom;

    public:
        BestBuy();

        string getBestBuyName();
        void setBestBuyName(string);

        double getCPUCost();
        void setCPUCost(double);

        double getGPUCost();
        void setGPUCost(double);

        double getPowerSupplyCost();
        void setPowerSupplyCost(double);

        double getComputerCaseCost();
        void setComputerCaseCost(double);

        double getInternetCardCost();
        void setInternetCardCost(double);

        double getKeyboardMouseCost();
        void setKeyboardMouseCost(double);

        double getPreComputerCost();
        void setPreComputerCost(double);

        double getAntiVirusCost();
        void setAntiVirusCost(double);

        double getVPNCost();
        void setVPNCost(double);

        double getIP2Cost();
        void setIP2Cost(double);

        double getIP3Cost();
        void setIP3Cost(double);

        double getIP4Cost();
        void setIP4Cost(double);

        double getIP5Cost();
        void setIP5Cost(double);

        int getServerRoom();
        void setServerRoom(int);

        void turingRoom();
        void ellisRoom();
        void johnsonRoom();
        void hopperRoom();
        void mooreRoom();
};