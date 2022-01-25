#include <iostream>

using namespace std;

class Game{
    private:
        string playerName;
        char response;
        int response2;
        bool isTrue;
        bool isTrue1;
        int bestBuyMenu;
        int computerPartsMenu;
        int activitiesMenu;
        int itemCount;
        int maxItemsCompRepair;
        double totalCost;
        int userRPC;
        int compRPC;
        int ranNum;
        int hackersDefeated;
        int r1;
        int r2;
        int r3;
        int r4;
        int r5;
        int r6;
        int r7;
        int r8;
        int r9;
        double battleOutcome;
        char move;
        string problems[4];
        string answers[4];
        Player userPlayer;
        BestBuy bestBuy;
        Hacker hacker;
        Map map;

    public:
        Game();

        void start();

        void serverRoom1();

        void serverRoom2();

        void serverRoom3();

        void serverRoom4();

        void serverRoom5();

        void end();

        void displayBestBuyMenu();

        void displayActivitiesMenu();

        void displayMapInfo();

        void statusUpdate();

        void RPS();

        void endOfGameStats();
};