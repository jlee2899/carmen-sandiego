#include <iostream>
#include <vector>

using namespace std;

class Hacker{
    private:
        string hackerName;
        int hackerRoom;
        int progressLevel;
        vector <string> vecHackerNames;
        vector <int> vecServerRoom;
        
    public:
        Hacker();

        string getHackerName(int);
        void setHackerName(int, string);

        int getServerRoom(int);
        void setServerRoom(int, int);

        int getProgressLevel();
        void setProgressLevel(int);

        void sortHackerNR();

        void displayHackerNames();

};