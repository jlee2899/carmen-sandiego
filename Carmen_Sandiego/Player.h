#include <iostream>
#include <vector>

using namespace std;

class Player{
    private:
        string playerName;
        int frustrationLevel;
        double dogeCoin;
        int computer;
        int IPL;
        int VPN;
        int antiVirus;
        int compMaintLvl;
        int compVirus;
        vector <int> myCompParts;  
        
    public:
        Player();

        string getPlayerName();
        void setPlayerName(string);

        int getFrustrationLevel();
        void setFrustrationLevel(int);

        double getDogeCoin();
        void setDogeCoin(double);

        int getComputer();
        void setComputer(int);

        int getIPL();
        void setIPL(int);

        int getVPN();
        void setVPN(int);

        int getAntiVirus();
        void setAntiVirus(int);

        int getCompMaintLvl();
        void setCompMaintLvl(int);

        int getMyCompParts(int);
        void setMyCompParts(int, int);

        int getCompVirus();
        void setCompVirus(int);

        void displayMyCompParts();
};