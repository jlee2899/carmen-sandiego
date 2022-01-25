#include <iostream>
#include <fstream>
#include "Player.h"
#include "BestBuy.h"
#include "Map.h"
#include "Hacker.h"
#include "Game.h"

using namespace std;

Game::Game(){
    //Create other class objects here and set them to default
    //Set private variables here like isTrue, bestBuyMenu
    isTrue = false;
    isTrue1 = false;
    bestBuyMenu = 0;
    computerPartsMenu = 0;
    activitiesMenu = 0;
    itemCount = 0;
    maxItemsCompRepair = 0;
    totalCost = 0;
    userRPC = 0;
    compRPC = 0;
    ranNum = 0;
    battleOutcome = 0;
    hackersDefeated = 0;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;
    r7 = 0;
    r8 = 0;
    r9 = 0;
    move;
}

void Game::start(){
    //Start of the game 
    cout << "\t ***** CARMEN SANDIEGO *****" << endl;
    cout << endl;
    cout << "Welcome to Where in the Code is Carmen Sandiego" << endl;
    cout << endl;

    cout << "Please enter your player name: ";
    getline(cin, playerName); //Using getline in case user enters a space in between the name
    userPlayer.setPlayerName(playerName); //Updating player name
    cout << endl;

    cout << "Welcome, " << userPlayer.getPlayerName() << "!" << " Before you start on your adventure," << endl;
    cout << "you will first visit Best Buy to purchase your supplies." << endl;
    cout << "Do you wish to go to Best Buy now (Y/N)? ";
    cin >> response;
    cout << endl;

    //Visiting Best Buy at the start of the game
    while(isTrue == false){ //While statement to continue asking if player wants to go to Best Buy until boolean expression isTrue == true
        if(response == 'y' || response == 'Y'){ //If response is a yes, print and do whats below
            cout << "\t ***** BEST BUY *****" << endl;
            cout << endl;
            cout << "Welcome to Best Buy " << userPlayer.getPlayerName() << ". " << "Here are some information." << endl;
            cout << "You will start with 200 dogecoins, 1 computer, and 1 VPN." << endl;
            cout << "You will want to spend your money wisely, depending on what you need:" << endl;
            cout << endl;

            cout << "COMPUTER PARTS: If your computer breaks, you will need 5 computer parts" << endl;
            cout << "\t\t" << "to make a new computer." << endl;
            cout << "ANTIVIRUS SOFTWARE: If your computer is infected with a deadly virus," <<endl;
            cout << "\t\t" << "the antivirus software will get rid of the virus." << endl;
            cout << "VIRTUAL PRIVATE NETWORK (VPN): The more VPNs you have, the harder it is" <<endl;
            cout << "\t\t" << "for a hacker to infect your computer with a virus." << endl;
            cout << "INTERNET PROVIDER: Better internet will be more reliable for your hacking" <<endl;
            cout << endl;

            cout << "You can spend all the money now before you start your journey." << endl;
            cout << "You will have more chances to visit Best Buy again." << endl;
            cout << "Saving your money might be a good idea, but be careful" << endl;
            cout << "you wont be able to get the same prices at a different Best Buy" << endl;
            cout << endl;
        
            while(bestBuyMenu != 5){ //While loop to continue looping through each Best Buy section until player decides to leave Best Buy
                cout << "Which section would you like to shop in?" << endl;
                cout << "1. Computer Parts" << endl;
                cout << "2. Antivirus Software" << endl;
                cout << "3. Virtual Private Network (VPN)" << endl;
                cout << "4. Internet Provider" << endl;
                cout << "5. Exit" << endl;
                cin >> bestBuyMenu;
                cout << endl;

                switch(bestBuyMenu){ //Switch statements for best buy menu
                    case 1: //Computer parts section
                        while(computerPartsMenu != 8){ //While statement to keep looping whats below until user selects option 8
                            cout << "Choose from the following computer parts (MAX 2):" << endl;
                            cout << "1. CPU: 10 DC" << endl;
                            cout << "2. GPU: 20 DC" << endl;
                            cout << "3. Power Supply: 5 DC" << endl;
                            cout << "4. Computer Case: 15 DC" << endl;
                            cout << "5. Internet Card: 5 DC" << endl;
                            cout << "6. Keyboard and Mouse: 10 DC" << endl;
                            cout << "7. Premade Computer: 100 DC" << endl;
                            cout << "8. Shop other sections" << endl;
                            cin >> computerPartsMenu;
                            cout << endl;
                                switch(computerPartsMenu){ //Nested switch statement for computer parts menu
                                    case 1: //CPU
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        }
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(0) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getCPUCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " CPU(s) " << "for " << bestBuy.getCPUCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getCPUCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(0, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(0) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getCPUCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " CPU(s) " << "for " << bestBuy.getCPUCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getCPUCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(0, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 2: //GPU
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        }
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(1) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getGPUCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " GPU(s) " << "for " << bestBuy.getGPUCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getGPUCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(1, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(1) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getGPUCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " GPU(s) " << "for " << bestBuy.getGPUCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getGPUCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(1, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 3: //Power supply
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        }
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(2) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getPowerSupplyCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Power Supply(s) " << "for " << bestBuy.getPowerSupplyCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPowerSupplyCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(2, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(1) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getPowerSupplyCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Power Supply(s) " << "for " << bestBuy.getPowerSupplyCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPowerSupplyCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(2, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 4: //Computer case
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        }
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(3) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getComputerCaseCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Computer Case(s) " << "for " << bestBuy.getComputerCaseCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getComputerCaseCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(3, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(3) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getComputerCaseCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Computer Case(s) " << "for " << bestBuy.getComputerCaseCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getComputerCaseCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(3, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 5: //Internet card
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        }
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(4) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getInternetCardCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Internet Card(s) " << "for " << bestBuy.getInternetCardCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getInternetCardCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(4, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(4) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getInternetCardCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Internet Card(s) " << "for " << bestBuy.getInternetCardCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getInternetCardCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(4, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 6: //Keyboard and Mouse
                                        cout << "Please enter how many you want: ";
                                        cin >> itemCount;
                                        cout << endl;

                                        if(itemCount > 2){ //If the user tries to buy more than 2
                                            cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                            cout << endl;
                                        } 
                                        else if(itemCount <= 0){ //If the user tries to buy none or enters negative number
                                            cout << "Please enter a valid number!" << endl;
                                            cout << endl;
                                        }
                                        else{ //Else the user enters 1 or 2
                                            if(itemCount == 1 && userPlayer.getMyCompParts(5) < 2){ //Checking to see if user has enough space to add 1 more item
                                                if(userPlayer.getDogeCoin() >= bestBuy.getKeyboardMouseCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Keyboard and Mouse(s) " << "for " << bestBuy.getKeyboardMouseCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getKeyboardMouseCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(5, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else if(itemCount == 2 && userPlayer.getMyCompParts(5) == 0){ //Checking to see if user has enough space to add 2 more items
                                                if(userPlayer.getDogeCoin() >= bestBuy.getKeyboardMouseCost() * itemCount){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased " << itemCount << " Keyboard and Mouse(s) " << "for " << bestBuy.getKeyboardMouseCost() * itemCount << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getKeyboardMouseCost() * itemCount); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(5, itemCount); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase item
                                                    cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                            else{ //User already has maximum of 2 items in their inventory or not enough space
                                                cout << "You don't have enough space in your inventory!" << endl;
                                                cout << "Check your inventory and come back." << endl;
                                                cout << endl;
                                                userPlayer.displayMyCompParts();
                                                cout << endl;
                                            }
                                        }
                                        break;

                                    case 7: //Premade computer
                                        cout << "You can have 1 extra premade computer." << endl;
                                        cout << "Would you like to buy a premade computer? (Y/N) ";
                                        cin >> response;
                                        cout << endl;

                                        if(response == 'n' || response == 'N'){ //If the user enters no do whats below
                                            cout << "Thank you for visiting this section." << endl;
                                            cout << endl;
                                        }
                                        else if(response == 'y' || response == 'Y'){ //If the user enters yes
                                            if(userPlayer.getMyCompParts(6) == 0){ //Checking to see if user has enough space to add 1 premade computer
                                                if(userPlayer.getDogeCoin() >= bestBuy.getPreComputerCost()){ //Checking to see if user has enough dogecoin to buy item
                                                    cout << "You have purchased 1 Premade Computer for " << bestBuy.getPreComputerCost() << " DC." << endl;
                                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPreComputerCost()); //Updating user dogecoin
                                                    userPlayer.setMyCompParts(6, 1); //Updating user computer parts vector
                                                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                                    cout << endl;
                                                    userPlayer.displayMyCompParts();
                                                    cout << endl;
                                                }
                                                else{ //User does not have enough dogecoin to purchase
                                                    cout << "You do not have enough Dogecoin to purchase a premade computer!" << endl;
                                                    cout << endl;
                                                }
                                            }
                                        }
                                        else{ //If user enters anything other than yes or no
                                            cout << "Please enter a valid response!" << endl;
                                            cout << endl;
                                        }
                                        break;

                                    case 8: //Exit
                                        cout << "Leaving Computer Parts Section..." << endl;
                                        cout << endl;
                                        break;

                                    default: //Anything other than 1-8
                                        cout << "Invalid input. Choose between 1-8" << endl;
                                        cout << endl;
                                        break;
                                }
                        }
                        computerPartsMenu = 0; //Setting the computer parts menu back to 0 so that it can print the menu again after exiting the computer parts section
                        break;
                        
                    case 2: //Antivirus software section
                        cout << "Antivirus Software: " << bestBuy.getAntiVirusCost() << " Dogecoin" << endl;
                        cout << "How many antivirus softwares do you want? ";
                        cin >> itemCount;
                        cout << endl;

                        if(itemCount < 0){ //User enters a negative number
                            cout << "Enter a positive number!" << endl;
                            cout << endl;
                        }
                        else{ //All positive numbers
                            if(itemCount * bestBuy.getAntiVirusCost() <= userPlayer.getDogeCoin()){ //Checking to see if user has enough dogecoin to purchase
                                totalCost = itemCount * bestBuy.getAntiVirusCost(); //Variable to keep tract of the total cost of item
                                cout << "You have purchased " << itemCount << " antivirus software(s) " << "for " << totalCost << " Dogecoin." << endl;
                                userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                                userPlayer.setAntiVirus(userPlayer.getAntiVirus() + itemCount); //Updating antivirus amount
                                cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                cout << endl;
                            }
                            else{ //User does not have enough dogecoin
                                cout << "You do not have enough Dogecoins to buy that many antivirus softwares!" << endl;
                                cout << "Check how much Dogecoin you have." << endl;
                                cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                cout << endl;
                            }
                        }
                        break;

                    case 3: //VPN section
                        cout << "VPN: " << bestBuy.getVPNCost() << " Dogecoin" << endl;
                        cout << "How many VPNs do you want? ";
                        cin >> itemCount;
                        cout << endl;

                        if(itemCount < 0){ //User enters a negative number
                            cout << "Enter a positive number!" << endl;
                            cout << endl;
                        }
                        else{ //All positive numbers
                            if(itemCount * bestBuy.getVPNCost() <= userPlayer.getDogeCoin()){ //Checking to see if user has enough dogecoin to purchase
                                totalCost = itemCount * bestBuy.getVPNCost(); //Variable to keep tract of the total cost of item
                                cout << "You have purchased " << itemCount << " VPN(s) " << "for " << totalCost << " Dogecoin." << endl;
                                userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                                userPlayer.setVPN(userPlayer.getVPN() + itemCount); //Updating VPN amount
                                cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                cout << endl;
                            }
                            else{ //User does not have enough dogecoin
                                cout << "You do not have enough Dogecoins to buy that many VPNs!" << endl;
                                cout << "Check how much Dogecoin you have." << endl;
                                cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                cout << endl;
                            }
                        }
                        break;

                    case 4: //Internet provider section
                        cout << "Internet Provider level 2: " << bestBuy.getIP2Cost() << " Dogecoin" << endl;
                        cout << "Internet Provider level 3: " << bestBuy.getIP3Cost() << " Dogecoin" << endl;
                        cout << "Internet Provider level 4: " << bestBuy.getIP4Cost() << " Dogecoin" << endl;
                        cout << "Internet Provider level 5: " << bestBuy.getIP5Cost() << " Dogecoin" << endl;
                        cout << "Enter the internet provider level you want to purchase: ";
                        cin >> response2;
                        cout << endl;

                        if(response2 < 2 || response2 > 5){ //User enters number other than 2-5
                            cout << "Invalid internet provider level!" << endl;
                            cout << endl;
                        }
                        else if(response2 == 2 && userPlayer.getDogeCoin() >= bestBuy.getIP2Cost()){ //Checking to see if user has enough to buy level 2
                            totalCost = bestBuy.getIP2Cost();
                            cout << "You have purchased internet provider level 2 for " << totalCost << " Dogecoin." << endl;
                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                            userPlayer.setIPL(2); //Updating internet provider level
                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                            cout << endl;
                        }
                        else if(response2 == 3 && userPlayer.getDogeCoin() >= bestBuy.getIP3Cost()){ //Checking to see if user has enough to buy level 3
                            totalCost = bestBuy.getIP3Cost();
                            cout << "You have purchased internet provider level 3 for " << totalCost << " Dogecoin." << endl;
                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                            userPlayer.setIPL(3); //Updating internet provider level
                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                            cout << endl;
                        }
                        else if(response2 == 4 && userPlayer.getDogeCoin() >= bestBuy.getIP4Cost()){ //Checking to see if user has enough to buy level 4
                            totalCost = bestBuy.getIP4Cost();
                            cout << "You have purchased internet provider level 4 for " << totalCost << " Dogecoin." << endl;
                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                            userPlayer.setIPL(4); //Updating internet provider level
                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                            cout << endl;
                        }
                        else if(response2 == 5 && userPlayer.getDogeCoin() >= bestBuy.getIP5Cost()){ //Checking to see if user has enough to buy level 5
                            totalCost = bestBuy.getIP5Cost();
                            cout << "You have purchased internet provider level 5 for " << totalCost << " Dogecoin." << endl;
                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost); //Updating user dogecoin
                            userPlayer.setIPL(5); //Updating internet provider level
                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                            cout << endl;
                        }
                        else{ //User does not have enough dogecoin to purchase item
                            cout << "You do not have enough Dogecoin to buy the selected internet provider level." << endl;
                            cout << "Check how much Dogecoin you have." << endl;
                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                            cout << endl;
                        }
                        break;

                    case 5: //Exiting Best Buy
                        cout << "Exiting Best Buy..." << endl;
                        cout << endl;
                        break;
                    
                    default: //If the player enters anything other than 1-5
                        cout << "Invalid input. Choose between 1-5" << endl;
                        cout << endl;
                        break;
                }
            }

            isTrue = true; //Setting isTrue to true in order to stop the while loop from asking the player if they want to go to Best Buy
        }

        else if(response == 'n' || response == 'N'){ //If response is a no, print whats below
            cout << "What are you waiting for! Hurry up and buy your supplies." << endl;
            cout << "We dont have time to waste. The hackers are already on it." << endl;
            cout << "Do you wish to go to Best Buy now (Y/N)? ";
            cin >> response;
            cout << endl;

            if(response == 'n'|| response == 'N'){ //If the player's response is a no again, print whats below
                cout << "Still not ready... It's time to decide now." << endl;
                cout << "Do you wish to go to Best Buy now (Y/N)? ";
                cin >> response;
                cout << endl;
            }
        }

        else{ //If the response entered is anything other than yes or no, print whats below
            cout << "Invalid input. Please enter Y or N: "; 
            cin >> response;
            cout << endl;
        }
    }

    //Transition from Best Buy to server room
    isTrue = false; //Setting isTrue to be false again 
    cout << userPlayer.getPlayerName() << ", are you ready to fight the hackers and stop Carmen Sandiego (Y/N)? ";
    cin >> response;
    cout << endl;

    while(isTrue == false){ //While statement to continue asking if player wants to go to Best Buy until boolean expression isTrue == true
        if(response == 'y' || response == 'Y'){
            cout << "Good luck " << userPlayer.getPlayerName() << "!" << " There is no turning back now." << endl;
            cout << "You will be spawned to the first server room." << endl;
            cout << endl;
            isTrue = true;
        }

        else if(response == 'n' || response == 'N'){
            cout << "Make your final preparations " << userPlayer.getPlayerName() << "." << endl;
            cout << "Are you ready to head to the first server room (Y/N)? ";
            cin >> response;
            cout << endl;
        }

        else{
            cout << "Invalid input. Please enter Y or N. ";
            cin >> response; 
            cout << endl;
        }
    }
}

void Game::serverRoom1(){
    //Updating best buy item costs and spawning BB, NPC, Hacker
    bestBuy.turingRoom(); 
    map.spawnBestBuy(0, 2);  
    map.spawnNPC(0, 7);
    map.spawnNPC(3, 2);
    map.spawnNPC(4, 6);
    map.spawnHacker(1, 4);
    isTrue1 = false;

    while(isTrue1 == false){ //While loop to continue looping whats below until isTrue1 == true
        if(map.getHackerCount() > 0){ //If the hacker count is greater than 0 
            bestBuyMenu = 0;
            cout << "[Turing Server Room]" << endl;
            displayMapInfo(); //Displays the player position, # of hackers, and # of npcs
            cout << endl;
            map.displayMap();
            cout << endl;
            displayActivitiesMenu(); //Main for the game, sets isTrue1 to true 
        }

        else{ //If the hacker count is is equal to 0
            cout << "You have successfully defeated all hackers in this room!" << endl;
            cout << "You will be spawned to the next server room." << endl;
            cout << endl;
            isTrue1 = true;
        }
    }
}

void Game::serverRoom2(){
    //Updating best buy item costs and spawning BB, NPC, Hacker
    bestBuy.ellisRoom();
    map.resetMap();
    map.spawnBestBuy(1, 2);
    map.spawnNPC(2, 6);
    map.spawnNPC(3, 2);
    map.spawnHacker(0, 4);
    map.spawnHacker(4, 4);
    isTrue1 = false; //Setting isTrue to false again so the while loop will run

    while(isTrue1 == false){ //While loop to continue looping whats below until isTrue == true
        if(map.getHackerCount() > 0){ //If the hacker count is greater than 0
            bestBuyMenu = 0;
            cout << "[Ellis Server Room]" << endl;
            displayMapInfo(); //Displays the player position, # of hackers, and # of npcs
            cout << endl;
            map.displayMap();
            cout << endl;
            displayActivitiesMenu(); //Main for the game, sets isTrue1 to true 
        }
        
        else{ //If the hacker count is is equal to 0
            cout << "You have successfully defeated all hackers in this room!" << endl;
            cout << "You will be spawned to the next server room." << endl;
            cout << endl;
            isTrue1 = true;
        }
    }
}

void Game::serverRoom3(){
    //Updating best buy item costs and spawning BB, NPC, Hacker
    bestBuy.johnsonRoom(); 
    map.resetMap();
    map.spawnBestBuy(2, 4);
    map.spawnNPC(0, 5);
    map.spawnNPC(4, 2);
    map.spawnHacker(1, 1);
    map.spawnHacker(3, 7);
    isTrue1 = false; //Setting isTrue to false again so the while loop will run

    while(isTrue1 == false){ //While loop to continue looping whats below until isTrue == true
        if(map.getHackerCount() > 0){ //If the hacker count is greater than 0
            bestBuyMenu = 0;
            cout << "[Johnson Server Room]" << endl;
            displayMapInfo(); //Displays the player position, # of hackers, and # of npcs
            cout << endl;
            map.displayMap();
            cout << endl;
            displayActivitiesMenu(); //Main for the game, sets isTrue1 to true
        }
        
        if(map.getHackerCount() <= 0){ //If the hacker count is is equal to 0
            cout << "You have successfully defeated all hackers in this room!" << endl;
            cout << "You will be spawned to the next server room." << endl;
            cout << endl;
            isTrue1 = true;
        }
    }
}

void Game::serverRoom4(){
    //Updating best buy item costs and spawning BB, NPC, Hacker
    bestBuy.hopperRoom(); 
    map.resetMap();
    map.spawnBestBuy(3, 6);
    map.spawnNPC(1, 6);
    map.spawnHacker(1, 3);
    map.spawnHacker(3, 1);
    map.spawnHacker(4, 4);
    isTrue1 = false; //Setting isTrue to false again so the while loop will run

    while(isTrue1 == false){ //While loop to continue looping whats below until isTrue == true
        if(map.getHackerCount() > 0){ //If the hacker count is greater than 0
            bestBuyMenu = 0;
            cout << "[Hopper Server Room]" << endl;
            displayMapInfo(); //Displays the player position, # of hackers, and # of npcs
            cout << endl;
            map.displayMap();
            cout << endl;
            displayActivitiesMenu(); //Main for the game, sets isTrue1 to true
        }
        
        else{ //If the hacker count is is equal to 0
            cout << "You have successfully defeated all hackers in this room!" << endl;
            cout << "You will be spawned to the next server room." << endl;
            cout << endl;
            isTrue1 = true;
        }
    }
}

void Game::serverRoom5(){
    //Updating best buy item costs and spawning BB, NPC, Hacker
    bestBuy.mooreRoom();
    map.resetMap();
    map.spawnBestBuy(4, 8);
    map.spawnNPC(2, 4);
    map.spawnHacker(0, 7);
    map.spawnHacker(4, 0);
    map.spawnHacker(4, 4);
    isTrue1 = false; //Setting isTrue to false again so the while loop will run

    while(isTrue1 == false){ //While loop to continue looping whats below until isTrue == true
        if(map.getHackerCount() > 0){ //If the hacker count is greater than 0
            bestBuyMenu = 0;
            cout << "[Moore Server Room]" << endl;
            displayMapInfo(); //Displays the player position, # of hackers, and # of npcs
            cout << endl;
            map.displayMap();
            cout << endl;
            displayActivitiesMenu(); //Main for the game, sets isTrue1 to true
        }
        
        else{ //If the hacker count is is equal to 0 or basically when all hackers are defeated
            cout << "You have successfully defeated all hackers!" << endl;
            cout << endl;
            isTrue1 = true;
        }
    }
}

void Game::end(){
    //Implement end conditions of the game here
    cout << "\t ****** CONGRATS ******" << endl;
    cout << "Dear, " << userPlayer.getPlayerName() << "." << "This is the end of the game." << endl;
    cout << "You have successfully defeated all hackers in each server room!" << endl;
    cout << "These were the stats you finished the game with:" << endl;
    cout << endl;
    endOfGameStats();
    cout << "Thank you for playing the game!" << endl;
    exit(0);
}

void Game::displayBestBuyMenu(){
    //Same best buy menu as the one in start() just condensed without the extra information from the beginning
    cout << "\t ***** " << bestBuy.getBestBuyName() << " *****" << endl;
    cout << endl;
    cout << "Hello, " << userPlayer.getPlayerName() << "." <<  " Welcome to " << bestBuy.getBestBuyName() << ". " << endl;
    cout << "Here are some information about the items:" << endl;
    cout << endl;

    cout << "COMPUTER PARTS: If your computer breaks, you will need 5 computer parts" << endl;
    cout << "\t\t" << "to make a new computer." << endl;
    cout << "ANTIVIRUS SOFTWARE: If your computer is infected with a deadly virus," <<endl;
    cout << "\t\t" << "the antivirus software will get rid of the virus." << endl;
    cout << "VIRTUAL PRIVATE NETWORK (VPN): The more VPNs you have, the harder it is" <<endl;
    cout << "\t\t" << "for a hacker to infect your computer with a virus." << endl;
    cout << "INTERNET PROVIDER: Better internet will be more reliable for your hacking" <<endl;
    cout << endl;

    while(bestBuyMenu != 5){ //While loop to continue looping through each Best Buy section until player decides to leave Best Buy
        cout << "Which section would you like to shop in?" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Exit" << endl;
        cin >> bestBuyMenu;
        cout << endl;

        switch(bestBuyMenu){
            case 1: //Computer parts section
                while(computerPartsMenu != 8){
                    cout << "Choose from the following computer parts (MAX 2):" << endl;
                    cout << "1. CPU: " << bestBuy.getCPUCost() << " DC" << endl;
                    cout << "2. GPU: " << bestBuy.getGPUCost() << " DC" << endl;
                    cout << "3. Power Supply: " << bestBuy.getPowerSupplyCost() << " DC" << endl;
                    cout << "4. Computer Case: " << bestBuy.getComputerCaseCost() << " DC" << endl;
                    cout << "5. Internet Card: " << bestBuy.getInternetCardCost() << " DC" << endl;
                    cout << "6. Keyboard and Mouse: " << bestBuy.getKeyboardMouseCost() << " DC" << endl;
                    cout << "7. Premade Computer: " << bestBuy.getPreComputerCost() << " DC" << endl;
                    cout << "8. Shop other sections" << endl;
                    cin >> computerPartsMenu;
                    cout << endl;
                        switch(computerPartsMenu){
                            case 1: //CPU
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(0) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getCPUCost()){
                                            cout << "You have purchased " << itemCount << " CPU(s) " << "for " << bestBuy.getCPUCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getCPUCost());
                                            userPlayer.setMyCompParts(0, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(0) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getCPUCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " CPU(s) " << "for " << bestBuy.getCPUCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getCPUCost() * itemCount);
                                            userPlayer.setMyCompParts(0, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 2: //GPU
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(1) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getGPUCost()){
                                            cout << "You have purchased " << itemCount << " GPU(s) " << "for " << bestBuy.getGPUCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getGPUCost());
                                            userPlayer.setMyCompParts(1, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(1) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getGPUCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " GPU(s) " << "for " << bestBuy.getGPUCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getGPUCost() * itemCount);
                                            userPlayer.setMyCompParts(1, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 3: //Power supply
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(2) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getPowerSupplyCost()){
                                            cout << "You have purchased " << itemCount << " Power Supply(s) " << "for " << bestBuy.getPowerSupplyCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPowerSupplyCost());
                                            userPlayer.setMyCompParts(2, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(1) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getPowerSupplyCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " Power Supply(s) " << "for " << bestBuy.getPowerSupplyCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPowerSupplyCost() * itemCount);
                                            userPlayer.setMyCompParts(2, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 4: //Computer case
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(3) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getComputerCaseCost()){
                                            cout << "You have purchased " << itemCount << " Computer Case(s) " << "for " << bestBuy.getComputerCaseCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getComputerCaseCost());
                                            userPlayer.setMyCompParts(3, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(3) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getComputerCaseCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " Computer Case(s) " << "for " << bestBuy.getComputerCaseCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getComputerCaseCost() * itemCount);
                                            userPlayer.setMyCompParts(3, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 5: //Internet card
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(4) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getInternetCardCost()){
                                            cout << "You have purchased " << itemCount << " Internet Card(s) " << "for " << bestBuy.getInternetCardCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getInternetCardCost());
                                            userPlayer.setMyCompParts(4, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(4) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getInternetCardCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " Internet Card(s) " << "for " << bestBuy.getInternetCardCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getInternetCardCost() * itemCount);
                                            userPlayer.setMyCompParts(4, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 6: //Keyboard and Mouse
                                cout << "Please enter how many you want: ";
                                cin >> itemCount;
                                cout << endl;

                                if(itemCount > 2){
                                    cout << "You can have a maximum of 2 of each computer parts!" << endl;
                                    cout << endl;
                                }
                                else if(itemCount <= 0){
                                    cout << "Please enter a valid number!" << endl;
                                    cout << endl;
                                }
                                else{
                                    if(itemCount == 1 && userPlayer.getMyCompParts(5) < 2){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getKeyboardMouseCost()){
                                            cout << "You have purchased " << itemCount << " Keyboard and Mouse(s) " << "for " << bestBuy.getKeyboardMouseCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getKeyboardMouseCost());
                                            userPlayer.setMyCompParts(5, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else if(itemCount == 2 && userPlayer.getMyCompParts(5) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getKeyboardMouseCost() * itemCount){
                                            cout << "You have purchased " << itemCount << " Keyboard and Mouse(s) " << "for " << bestBuy.getKeyboardMouseCost() * itemCount << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getKeyboardMouseCost() * itemCount);
                                            userPlayer.setMyCompParts(5, itemCount);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase the amount you entered!" << endl;
                                            cout << endl;
                                        }
                                    }
                                    else{
                                        cout << "You don't have enough space in your inventory!" << endl;
                                        cout << "Check your inventory and come back." << endl;
                                        cout << endl;
                                        userPlayer.displayMyCompParts();
                                        cout << endl;
                                    }
                                }
                                break;

                            case 7: //Premade computer
                                cout << "You can have 1 extra premade computer." << endl;
                                cout << "Would you like to buy a premade computer? (Y/N) ";
                                cin >> response;
                                cout << endl;

                                if(response == 'n' || response == 'N'){
                                    cout << "Thank you for visiting this section." << endl;
                                    cout << endl;
                                }
                                else if(response == 'y' || response == 'Y'){
                                    if(userPlayer.getMyCompParts(6) == 0){
                                        if(userPlayer.getDogeCoin() >= bestBuy.getPreComputerCost()){
                                            cout << "You have purchased 1 Premade Computer for " << bestBuy.getPreComputerCost() << " DC." << endl;
                                            userPlayer.setDogeCoin(userPlayer.getDogeCoin() - bestBuy.getPreComputerCost());
                                            userPlayer.setMyCompParts(6, 1);
                                            cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                                            cout << endl;
                                            userPlayer.displayMyCompParts();
                                            cout << endl;
                                        }
                                        else{
                                            cout << "You do not have enough Dogecoin to purchase a premade computer!" << endl;
                                            cout << endl;
                                        }
                                    }
                                }
                                else{
                                    cout << "Please enter a valid response!" << endl;
                                    cout << endl;
                                }
                                break;

                            case 8: //Exit
                                cout << "Leaving Computer Parts Section..." << endl;
                                cout << endl;
                                break;

                            default: //Anything other than 1-8
                                cout << "Invalid input. Choose between 1-8." << endl;
                                cout << endl;
                                break;
                        }
                }
                computerPartsMenu = 0;
                break;
                
            case 2: //Antivirus software section
                cout << "Antivirus Software: " << bestBuy.getAntiVirusCost() << " Dogecoin" << endl;
                cout << "How many antivirus softwares do you want? ";
                cin >> itemCount;
                cout << endl;

                if(itemCount < 0){
                    cout << "Enter a positive number!" << endl;
                    cout << endl;
                }
                else{
                    if(itemCount * bestBuy.getAntiVirusCost() < userPlayer.getDogeCoin()){
                        totalCost = itemCount * bestBuy.getAntiVirusCost();
                        cout << "You have purchased " << itemCount << " antivirus software(s) " << "for " << totalCost << " Dogecoin." << endl;
                        userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                        userPlayer.setAntiVirus(userPlayer.getAntiVirus() + itemCount);
                        cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                        cout << endl;
                    }
                    else{
                        cout << "You do not have enough Dogecoins to buy that many antivirus softwares!" << endl;
                        cout << "Check how much Dogecoin you have." << endl;
                        cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                        cout << endl;
                    }
                }
                break;

            case 3: //VPN section
                cout << "VPN: " << bestBuy.getVPNCost() << " Dogecoin" << endl;
                cout << "How many VPNs do you want? ";
                cin >> itemCount;
                cout << endl;

                if(itemCount < 0){
                    cout << "Enter a positive number!" << endl;
                    cout << endl;
                }
                else{
                    if(itemCount * bestBuy.getVPNCost() < userPlayer.getDogeCoin()){
                        totalCost = itemCount * bestBuy.getVPNCost();
                        cout << "You have purchased " << itemCount << " VPN(s) " << "for " << totalCost << " Dogecoin." << endl;
                        userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                        userPlayer.setVPN(userPlayer.getVPN() + itemCount);
                        cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                        cout << endl;
                    }
                    else{
                        cout << "You do not have enough Dogecoins to buy that many VPNs!" << endl;
                        cout << "Check how much Dogecoin you have." << endl;
                        cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                        cout << endl;
                    }
                }
                break;

            case 4: //Internet provider section
                cout << "Internet Provider level 2: " << bestBuy.getIP2Cost() << " Dogecoin" << endl;
                cout << "Internet Provider level 3: " << bestBuy.getIP3Cost() << " Dogecoin" << endl;
                cout << "Internet Provider level 4: " << bestBuy.getIP4Cost() << " Dogecoin" << endl;
                cout << "Internet Provider level 5: " << bestBuy.getIP5Cost() << " Dogecoin" << endl;
                cout << "Enter the internet provider level you want to purchase: ";
                cin >> response2;
                cout << endl;

                if(response2 < 2 || response2 > 5){
                    cout << "Invalid internet provider level!" << endl;
                    cout << endl;
                }
                else if(response2 == 2 && userPlayer.getDogeCoin() >= bestBuy.getIP2Cost()){
                    totalCost = bestBuy.getIP2Cost();
                    cout << "You have purchased internet provider level 2 for " << totalCost << " Dogecoin." << endl;
                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                    userPlayer.setIPL(2);
                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                    cout << endl;
                }
                else if(response2 == 3 && userPlayer.getDogeCoin() >= bestBuy.getIP3Cost()){
                    totalCost = bestBuy.getIP3Cost();
                    cout << "You have purchased internet provider level 3 for " << totalCost << " Dogecoin." << endl;
                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                    userPlayer.setIPL(3);
                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                    cout << endl;
                }
                else if(response2 == 4 && userPlayer.getDogeCoin() >= bestBuy.getIP4Cost()){
                    totalCost = bestBuy.getIP4Cost();
                    cout << "You have purchased internet provider level 4 for " << totalCost << " Dogecoin." << endl;
                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                    userPlayer.setIPL(4);
                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                    cout << endl;
                }
                else if(response2 == 5 && userPlayer.getDogeCoin() >= bestBuy.getIP5Cost()){
                    totalCost = bestBuy.getIP5Cost();
                    cout << "You have purchased internet provider level 5 for " << totalCost << " Dogecoin." << endl;
                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() - totalCost);
                    userPlayer.setIPL(5);
                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                    cout << endl;
                }
                else{
                    cout << "You do not have enough Dogecoin to buy the selected internet provider level." << endl;
                    cout << "Check how much Dogecoin you have." << endl;
                    cout << "My Dogecoin: " << userPlayer.getDogeCoin() << endl;
                    cout << endl;
                }
                break;

            case 5: //Exiting Best Buy
                cout << "Thank you for shopping with us!" << endl;
                cout << "Exiting " << bestBuy.getBestBuyName() << "..." << endl;
                break;
            
            default: //If the player enters anything other than 1-5
                cout << "Invalid input. Choose between 1-5." << endl;
                cout << endl;
                break;
        }
    }

    bestBuyMenu = 0;
}

void Game::displayActivitiesMenu(){
    srand(time(NULL));
    while(activitiesMenu != 7){ //Looping until user enters 7
        statusUpdate(); //Displaying the stats of the player everytime before the main menu 
        cout << endl;
        cout << "Choose from the following actions:" << endl;
        cout << "1. Fight a Hacker" << endl;
        cout << "2. Speak to NPC" << endl;
        cout << "3. Repair your Computer" << endl;
        cout << "4. Use Antivirus Software" << endl;
        cout << "5. Travel the Server Room" << endl;
        cout << "6. Rock Paper Scissors" << endl;
        cout << "7. Quit" << endl;
        cin >> activitiesMenu;
        userPlayer.setFrustrationLevel(userPlayer.getFrustrationLevel() + 2); //Plus 2 on frustration level everytime user inputs activities menu
        userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 10 * userPlayer.getCompVirus()); //Once you have a virus, it will -10 * how many viruses everytime user inputs 
        cout << endl;

        switch(activitiesMenu){
            case 1: //Fighting hacker
                if(map.isHackerLocation() == false){ //Checking to see if hacker is on the same spot 
                    cout << "Huh??? There are no hackers to fight here..." << endl;
                    cout << endl;
                }
                else{ //If the hacker is on the same spot
                    if(bestBuy.getServerRoom() == 1){ //If you are a hacker in server room 1
                        ranNum = 0 + (rand() % 4); //Generating random number between 0 and 3 (Hackers are stored in vectors with the server room )
                        cout << "You ran into hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                        cout << "Choose the following options:" << endl;
                        cout << "1. Attack" << endl;
                        cout << "2. Forfeit" << endl;
                        cin >> response2;
                        cout << endl;

                        if(response2 == 1){ //If the player decides to fight the hacker
                            if(userPlayer.getCompMaintLvl() > 0){ //Checking to see if player has high enough computer maintenance
                                r1 = 1 + (rand() % 6); //Generating random number 1-6
                                r2 = 1 + (rand() % 6); //Generating random number 1-6
                                battleOutcome = (double)r1 * (double)userPlayer.getIPL() - (double)r2 * (double)hacker.getServerRoom(ranNum) * 1 / (double)userPlayer.getVPN();
                                if(battleOutcome > 0){ //Checking to see if player won
                                    cout << "You have won against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    map.setHackerCount(map.getHackerCount() - 1); //Subtracting from the hacker count
                                    hackersDefeated += 1; //Adding defeated hackers
                                    cout << "You earned 50 Dogecoin for the battle." << endl;
                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 50); //Updating dogecoin
                                    cout << endl;
                                    return;
                                }
                                else{ //Checking to see if hacker won
                                    cout << "You have lost against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    cout << "Your computer maintenance level dropped by 20%." << endl;
                                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 20); //Updating comp maint lvl
                                    hacker.setProgressLevel(hacker.getProgressLevel() + 25); //Updating Carmen Sandiegos progress level
                                    cout << endl;
                                    //10% chance of being infected with a virus
                                    r3 = 1 + (rand() % 10);
                                    if(r3 == 1){ //10% chance
                                        cout << "Oh no! Your computer was infected with a virus." << endl;
                                        userPlayer.setCompVirus(1); //Adding how many virus the computer has
                                        cout << endl;
                                    }
                                    return;
                                }
                            }
                            else{ //If the computer maint level is 0
                                cout << "You can only choose to attack when computer's maintenance level is above 0." << endl;
                                cout << endl;
                            }
                        }

                    }
                    if(bestBuy.getServerRoom() == 2){ //If you are a hacker in server room 2
                        ranNum = 4 + (rand() % 4); //Random number generator between 4-7 
                        cout << "You ran into hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                        cout << "Choose the following options:" << endl;
                        cout << "1. Attack" << endl;
                        cout << "2. Forfeit" << endl;
                        cin >> response2;
                        cout << endl;

                        if(response2 == 1){ //Attacking 
                            if(userPlayer.getCompMaintLvl() > 0){ //Checking to see if player has high enough computer maintenance
                                r1 = 1 + (rand() % 6); //Generating random number 1-6
                                r2 = 1 + (rand() % 6); //Generating random number 1-6
                                battleOutcome = ((double)r1 * (double)userPlayer.getIPL()) - ((double)r2 * (double)hacker.getServerRoom(ranNum)) * (1 / (double)userPlayer.getVPN());
                                if(battleOutcome > 0){ //Checking to see if player won 
                                    cout << "You have won against hacker " << hacker.getHackerName(ranNum) << "!" << endl; 
                                    map.setHackerCount(map.getHackerCount() - 1); //Subtracting from the hacker count
                                    hackersDefeated += 1; //Adding defeated hackers
                                    cout << "You earned 50 Dogecoin for the battle." << endl;
                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 50); //Updating dogecoin
                                    cout << endl;
                                    return;
                                }
                                else{ //If hacker won
                                    cout << "You have lost against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    cout << "Your computer maintenance level dropped by 20%." << endl;
                                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 20); //Updating comp maint lvl
                                    hacker.setProgressLevel(hacker.getProgressLevel() + 25); //Updating Carmen Sandiegos progress level
                                    cout << endl;
                                    //10% chance of being infected with a virus
                                    r3 = 1 + (rand() % 10);
                                    if(r3 == 1){
                                        cout << "Oh no! Your computer was infected with a virus." << endl;
                                        userPlayer.setCompVirus(1); //Adding how many virus the computer has
                                        cout << endl;
                                    }
                                    return;
                                }
                            }
                            else{
                                cout << "You can only choose to attack when computer's maintenance level is above 0." << endl;
                                cout << endl;
                            }
                        }
                    }
                    if(bestBuy.getServerRoom() == 3){ //If you are a hacker in server room 3
                        ranNum = 8 + (rand() % 4); //Random number generator between 8-11
                        cout << "You ran into hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                        cout << "Choose the following options:" << endl;
                        cout << "1. Attack" << endl;
                        cout << "2. Forfeit" << endl;
                        cin >> response2;
                        cout << endl;

                        if(response2 == 1){ //Attacking 
                            if(userPlayer.getCompMaintLvl() > 0){ //Checking to see if player has high enough computer maintenance
                                r1 = 1 + (rand() % 6); //Generating random number 1-6
                                r2 = 1 + (rand() % 6); //Generating random number 1-6
                                battleOutcome = (double)r1 * (double)userPlayer.getIPL() - (double)r2 * (double)hacker.getServerRoom(ranNum) * 1 / (double)userPlayer.getVPN();
                                if(battleOutcome > 0){ //Checking to see if player won
                                    cout << "You have won against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    map.setHackerCount(map.getHackerCount() - 1); //Subtracting from the hacker count
                                    hackersDefeated += 1; //Adding defeated hackers
                                    cout << "You earned 50 Dogecoin for the battle." << endl;
                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 50); //Updating dogecoin
                                    cout << endl;
                                    return;
                                }
                                else{ //If hacker won
                                    cout << "You have lost against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    cout << "Your computer maintenance level dropped by 20%." << endl;
                                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 20); //Updating comp maint lvl
                                    hacker.setProgressLevel(hacker.getProgressLevel() + 25); //Updating Carmen Sandiegos progress level
                                    cout << endl;
                                    //10% chance of being infected with a virus
                                    r3 = 1 + (rand() % 10);
                                    if(r3 == 1){
                                        cout << "Oh no! Your computer was infected with a virus." << endl;
                                        userPlayer.setCompVirus(1); //Adding how many virus the computer has
                                        cout << endl;
                                    }
                                    return;
                                }
                            }
                            else{
                                cout << "You can only choose to attack when computer's maintenance level is above 0." << endl;
                                cout << endl;
                            }
                        }
                    }
                    if(bestBuy.getServerRoom() == 4){ //If you are a hacker in server room 4
                        ranNum = 12 + (rand() % 4); //Random number generator between 12-15
                        cout << "You ran into hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                        cout << "Choose the following options:" << endl;
                        cout << "1. Attack" << endl;
                        cout << "2. Forfeit" << endl;
                        cin >> response2;
                        cout << endl;

                        if(response2 == 1){ //Attacking 
                            if(userPlayer.getCompMaintLvl() > 0){ //Checking to see if player has high enough computer maintenance
                                r1 = 1 + (rand() % 6); //Generating random number 1-6
                                r2 = 1 + (rand() % 6); //Generating random number 1-6
                                battleOutcome = (double)r1 * (double)userPlayer.getIPL() - (double)r2 * (double)hacker.getServerRoom(ranNum) * 1 / (double)userPlayer.getVPN();
                                if(battleOutcome > 0){ //Checking to see if player won
                                    cout << "You have won against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    map.setHackerCount(map.getHackerCount() - 1); //Subtracting from the hacker count
                                    hackersDefeated += 1; //Adding defeated hackers
                                    cout << "You earned 50 Dogecoin for the battle." << endl;
                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 50); //Updating dogecoin
                                    cout << endl;
                                    return;
                                }
                                else{ //If hacker won
                                    cout << "You have lost against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    cout << "Your computer maintenance level dropped by 20%." << endl; 
                                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 20); //Updating comp maint lvl
                                    hacker.setProgressLevel(hacker.getProgressLevel() + 25); //Updating Carmen Sandiegos progress level
                                    cout << endl;
                                    //10% chance of being infected with a virus
                                    r3 = 1 + (rand() % 10);
                                    if(r3 == 1){
                                        cout << "Oh no! Your computer was infected with a virus." << endl;
                                        userPlayer.setCompVirus(1); //Adding how many virus the computer has
                                        cout << endl;
                                    }
                                    return;
                                }
                            }
                            else{
                                cout << "You can only choose to attack when computer's maintenance level is above 0." << endl;
                                cout << endl;
                            }
                        }
                    }
                    if(bestBuy.getServerRoom() == 5){ //If you are a hacker in server room 4
                        ranNum = 16 + (rand() % 4); //Random number generator between 16-19
                        cout << "You ran into hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                        cout << "Choose the following options:" << endl;
                        cout << "1. Attack" << endl;
                        cout << "2. Forfeit" << endl;
                        cin >> response2;
                        cout << endl;

                        if(response2 == 1){ //Attacking 
                            if(userPlayer.getCompMaintLvl() > 0){ //Checking to see if player has high enough computer maintenance
                                r1 = 1 + (rand() % 6); //Generating random number 1-6
                                r2 = 1 + (rand() % 6); //Generating random number 1-6
                                battleOutcome = (double)r1 * (double)userPlayer.getIPL() - (double)r2 * (double)hacker.getServerRoom(ranNum) * 1 / (double)userPlayer.getVPN();
                                if(battleOutcome > 0){ //Checking to see if player won
                                    cout << "You have won against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    map.setHackerCount(map.getHackerCount() - 1); //Subtracting from the hacker count
                                    hackersDefeated += 1; //Adding defeated hackers
                                    cout << "You earned 50 Dogecoin for the battle." << endl;
                                    userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 50); //Updating dogecoin
                                    cout << endl;
                                    return;
                                }
                                else{ //If hacker won
                                    cout << "You have lost against hacker " << hacker.getHackerName(ranNum) << "!" << endl;
                                    cout << "Your computer maintenance level dropped by 20%." << endl;
                                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() - 20); //Updating comp maint lvl
                                    hacker.setProgressLevel(hacker.getProgressLevel() + 25); //Updating Carmen Sandiegos progress level
                                    cout << endl;
                                    //10% chance of being infected with a virus
                                    r3 = 1 + (rand() % 10);
                                    if(r3 == 1){ 
                                        cout << "Oh no! Your computer was infected with a virus." << endl;
                                        userPlayer.setCompVirus(1); //Adding how many virus the computer has
                                        cout << endl;
                                    }
                                    return;
                                }
                            }
                            else{
                                cout << "You can only choose to attack when computer's maintenance level is above 0." << endl;
                                cout << endl;
                            }
                        }
                    }
                }
                
                r4 = 1 + (rand() % 100); //Range from 1-100
                if(r4 <= 30){ //After any hacker battle, comp maint lvl has 30% chance to drop by 20%
                    userPlayer.setCompMaintLvl(userPlayer.getCompMaintLvl() + 25); //Updating comp maint level
                }
                break;

            case 2: //Speaking to npc
                if(map.isNPCLocation() == false){ //Checking to see if an NPC is on the same spot
                    cout << "There are no NPC(s) located in this spot." << endl;
                    cout << endl;
                }
                else{ //On the same spot
                    //Implement quiz here
                    ifstream inFile;
                    inFile.open("puzzles.txt");
                    if(inFile.is_open()){
                        string problem;
                        string temp;
                        int counter = 0;
                        while(getline(inFile, temp)){ //Getting each line
                            if(temp != "---"){ //If the line does not equal the delimeter
                                problem += '\n'; //Add new line
                                problem += temp; //Add temp to problem
                            }
                            else{ //If the line is equal to the delimeter
                                problems[counter] = problem; //Add the cumulative problem to the problems array
                                problem.clear(); //Clearing the strings in problem
                                counter++; //Increment counter
                            }
                        }
                    }

                    inFile.close();
                    inFile.open("answers.txt");
                    if(inFile.is_open()){
                        string temp;
                        int counter = 0;
                        while(getline(inFile, temp)){ //Getting each line
                            if(temp != "---"){ //If the line does not equal the delimeter
                                answers[counter] = temp; //Add temp to answer
                            }
                            else{ //If the line is equal to the delimeter
                                counter++; //Increment counter
                            }
                        }
                    }

                    inFile.close();
                    string userAnswer;
                    r5 = (rand() % 4); //Random number generator for problem and answer array
                    r6 = 1 + (rand() % 99); //Range from 1-99
                    r7 = (rand() % 7); //Random number for computer part
                    cout << "Welcome to puzzle time!" << endl;
                    cout << "Here are some information:" << endl;
                    cout << "If you get the answer correct, you will recieve a free computer part." << endl;
                    cout << "If you dont want to complete the puzzle, you can take a chance." << endl;
                    cout << "There is a 33" << "% " << "chance the NPC will be your ally." << endl;
                    cout << "There is a 33" << "% " << "chance the NPC will be neutral." << endl;
                    cout << "There is a 33" << "% " << "chance the NPC will be your enemy." << endl;
                    cout << "If the NPC is an enemy, they will steal a randomly selected computer part." << endl;
                    cout << endl;
                    cout << "Do you want complete the puzzle (Y/N)? ";
                    cin >> response;

                    if(response == 'y' || response == 'Y'){
                        cout << problems[r5] << endl; //Reading from a file the problem
                        cin >> userAnswer;
                        cout <<endl;
                        if(userAnswer == answers[r5]){ //If answer is correct 
                            cout << "You are correct!" << endl;
                            cout << "Here is a gift." << endl;
                            userPlayer.setMyCompParts(r7, 1); //Updating random computer part 
                            cout << endl;
                            userPlayer.displayMyCompParts(); //Displaying the new computer parts
                        }
                        else{
                            cout << "That was incorrect!" << endl;
                            cout << endl;

                        }
                    }
                    else{ //If you want to take a chance
                        if(r6 <= 33){ //This should be 33%
                            cout << "Today is your lucky day pal." << endl;
                            cout << endl;
                            userPlayer.setMyCompParts(r7, 1); //Updating random computer part 
                            cout << endl;
                            userPlayer.displayMyCompParts(); //Displaying the new computer parts
                        }
                        else if(r6 > 33 && r6 <= 66){ //This should be 33%
                            cout << "I am not your friend nor your enemy.." << endl;
                            cout << endl;
                            userPlayer.displayMyCompParts(); //Displaying the new computer parts
                        }
                        else{ //This should be 33%
                            if(userPlayer.getMyCompParts(r7) > 0){ //If the player has an item to take away
                                cout << "The NPC has stolen a computer part from your inventory" << endl;
                                userPlayer.setMyCompParts(r7, -1); //Updating comp parts
                                cout << endl;
                                userPlayer.displayMyCompParts(); //Displaying the new computer parts
                            }
                            else{ //Dont even have items
                                cout << "How pathethic... You dont even have any items for me to take!" << endl;
                                cout << endl;
                            }
                        }
                    }
                }
                break;
            case 3: //Repairing computer
                if(userPlayer.getCompVirus() != 0){
                    cout << "You can't repair your computer when you have a virus!" << endl;
                    cout << "First, recover your computer from the virus." << endl;
                    cout << endl;
                    break;
                }

                cout << "Here are some information about repairing your computer:" << endl;
                cout << "You will only be able to repair your computer if you have no" << endl;
                cout << "virus or the computer's maintenance level is less than 100" << "%. " << endl;
                cout << "Each computer part has a unique increase in maintenance level " << endl;
                cout << endl;

                userPlayer.displayMyCompParts();
                cout << endl;

                if(userPlayer.getCompMaintLvl() >= 100){
                    cout << "Your computer maintenance level is at max functionality" << endl;
                    cout << "You do not need to repair your computer." << endl;
                    cout << endl;
                }
                else{
                    cout << "Enter the amount you want to use: "  << endl;
                    cout << "1. CPU: ";
                    cin >> response2;

                    if(userPlayer.getMyCompParts(0) > 0 && userPlayer.getMyCompParts(0) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(0) - response2;
                        userPlayer.setMyCompParts(0, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }
                    cout << "2. GPU: ";
                    cin >> response2;

                    if(userPlayer.getMyCompParts(1) > 0 && userPlayer.getMyCompParts(1) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(1) - response2;
                        userPlayer.setMyCompParts(1, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }    
                    cout << "3. PowerSupply: ";
                    cin >> response2;

                    if(userPlayer.getMyCompParts(2) > 0 && userPlayer.getMyCompParts(2) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(2) - response2;
                        userPlayer.setMyCompParts(2, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }

                    cout << "4. Computer Case: ";
                    cin >> response2;
                    if(userPlayer.getMyCompParts(3) > 0 && userPlayer.getMyCompParts(3) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(3) - response2;
                        userPlayer.setMyCompParts(3, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }
                    cout << "5. Internet Card: ";
                    cin >> response2;

                    if(userPlayer.getMyCompParts(4) > 0 && userPlayer.getMyCompParts(4) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(4) - response2;
                        userPlayer.setMyCompParts(4, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }
                    cout << "6. Keyboard and Mouse: ";
                    cin >> response2;

                    if(userPlayer.getMyCompParts(5) > 0 && userPlayer.getMyCompParts(5) >= response2){
                        maxItemsCompRepair = userPlayer.getMyCompParts(5) - response2;
                        userPlayer.setMyCompParts(5, maxItemsCompRepair);
                        break;
                    }
                    else{
                        cout << "You dont have enough parts!" << endl;
                        cout << endl;
                    }
                }   
                break;
            case 4: //Using antivirus software
                if(userPlayer.getCompVirus() > 0){ //Checking to see if the computer has virus
                    cout << "Youre computer is infected with a virus!" << endl;
                    cout << "Do you want to use an antivirus software? (Y/N) ";
                    cin >> response;
                    if(response == 'y' || response == 'Y'){
                        cout << "Loading up the antivirus software..." << endl;
                        cout << "Your computer is now virus free!" << endl;
                        userPlayer.setCompVirus(0); //Updating the virus in computer
                        userPlayer.setAntiVirus(userPlayer.getAntiVirus() - 1); //Updating the antivirus amount
                    }  
                }
                else{
                    cout << "Youre computer does not have any virus yet" << endl;
                    cout << endl;
                }
                break;
            case 5: //Traveling the server room
                displayMapInfo();
                cout << endl;
                map.displayMap();
                cout << endl;
                cout << "Enter a valid move: " << endl;
                map.displayMoves();
                cout << "Input a move: ";
                cin >> move;
                cout << endl;
                map.executeMove(move);
                userPlayer.setDogeCoin(userPlayer.getDogeCoin() + 5 + (userPlayer.getMyCompParts(1) * 5)); //Updating the dogecoin for every move and for GPU

                if(map.isHackerLocation()){ //If player is on the same spot as hacker
                    cout << "You found a hacker at location (" << map.getPlayerRowPosition() << ", " << map.getPlayerColPosition() << ")" << endl; 
                    cout << endl;
                }
                if(map.isBestBuyLocation()){ //If the player is on the same spot as bestbuy
                    cout << "You found a Best Buy at location (" << map.getPlayerRowPosition() << ", " << map.getPlayerColPosition() << ")" << endl;
                    cout << endl;
                    cout << "Do you want to visit Best Buy now (Y/N)? ";
                    cin >> response;
                    cout << endl;

                    if(response == 'y' || response == 'Y'){
                        displayBestBuyMenu(); //Function that brings up the best buy menu function
                        cout << endl;
                    }

                    else if(response == 'n' || response == 'N'){
                        cout << "Come back again later!" << endl;
                        cout << endl;
                    }

                    else{
                        cout << "Invalid response!" << endl;
                        cout << endl;
                    }
                }
                if(map.isNPCLocation()){ //If NPC is on the same spot as player 
                    cout << "You found an NPC at location (" << map.getPlayerRowPosition() << ", " << map.getPlayerColPosition() << ")" << endl;
                    cout << endl;
                }

                map.displayMap();
                cout << endl;
                break;
            case 6: //Rock Paper Scissors
                if(userPlayer.getFrustrationLevel() >= 5){ //Need to have more than 5 frustration level
                    cout << "Let's play a game of Rock Paper Scissors." << endl;
                    cout << "If you win, your frustration level will drop by 5!" << endl;
                    cout << endl;
                    RPS(); //Rock paper scissors function
                }
                else{
                    cout << "Your frustration level is already low buddy.." << endl;
                    cout << endl;
                }

                cout << endl;
                break;
            case 7: //Quit
                cout << "*** GAME OVER ***" << endl;
                cout << "What a sore loser!" << endl;
                cout << "Exiting the game..." << endl;
                cout << endl;
                exit(0);
            default: //Anything other than 1-7
                cout << "Invalid input. Choose between 1-7." << endl;
                cout << endl;
                break;
        }

        r8 = 1 + (rand() % 3);
        r9 = 1 + (rand() % 100);
        if(r9 <= 40){ //40% misfortune
            if(r8 == 1){ //Random chance to do this
                cout << "Unfortunately, a misfortune occured..." << endl;
                cout << "OH NO! Your antivirus software was robbed by Carmen's dastardly hackers!" << endl;
                userPlayer.setAntiVirus(userPlayer.getAntiVirus() - 1); //Updating the antivirus amount
                cout << endl;

            }
            else if(r8 == 2){ //Random chance to do this
                cout << "Unfortunately, a misfortune occured..." << endl;
                cout << "OH NO! Your computer broke!" << endl;
                userPlayer.setCompMaintLvl(0); //Setting comp main level to 0
                if(userPlayer.getCompMaintLvl() <= 0){ //If the comp maint level becomes 0
                    if(userPlayer.getMyCompParts(6) > 0){ //First check to see if player has a premade computer 
                        cout << "Lucky you had a premade computer." << endl;
                        cout << endl;
                        userPlayer.setCompMaintLvl(100); //Setting maint lvl to 100
                        userPlayer.setMyCompParts(6, 0);
                        break;
                    }
                    else{ //No premade computer means game over
                        cout << "*** GAME OVER ***" << endl;
                        cout << "You should have protected your computer!" << endl;
                        cout << "Exiting the game..." << endl;
                        cout << endl;
                        exit(0);
                    }
                }
            }
            else{ //Random chance to do this
                if(userPlayer.getFrustrationLevel() == 100){
                    cout << "OH NO! You have rage quit!" << endl;
                    cout << "Looks like you couldnt handle Carmen's hackers" << endl; 
                    exit(0);
                }
            }
        }
        else{
            cout << "No misfortunes occured after completing an activity." << endl;
            cout << endl;
        }

        if(hacker.getProgressLevel() >= 100){ //Checking the progress level of the hackers
            cout << "*** GAME OVER ***" << endl;
            cout << "Carmen and her hackers stole all of our top secret files!" << endl;
            cout << endl;
            exit(0);
        }

        if(userPlayer.getFrustrationLevel() >= 100){ // Rage quitting
            cout << "*** GAME OVER ***" << endl;
            cout << "You have exceeded your frustration" << endl;
            cout << "level capacity. Take a breather!" << endl;
            cout << "Exiting the game..." << endl;
            cout << endl;
            exit(0);
        }

        /*
        if(userPlayer.getCompMaintLvl() <= 0){ //If the comp maint level becomes 0
            if(userPlayer.getMyCompParts(6) == 1){ //First check to see if player has a premade computer 
                cout << "Lucky you had a premade computer." << endl;
                cout << endl;
                userPlayer.setCompMaintLvl(100); //Setting maint lvl to 100
                userPlayer.setMyCompParts(6, 0);
            }
            else{ //No premade computer means game over
            cout << "*** GAME OVER ***" << endl;
            cout << "You should have protected your computer!" << endl;
            cout << "Exiting the game..." << endl;
            cout << endl;
            exit(0);
            }
        }
        */
    }
}

void Game::displayMapInfo(){
    cout << "Player Location: (" << map.getPlayerRowPosition() << ", " << map.getPlayerColPosition() << ")" << endl;
    cout << "# of Hackers: " << map.getHackerCount() << endl;
    cout << "# of NPCs: " << map.getNPCCount() << endl;
}

void Game::statusUpdate(){
    cout << "\t *My Stats*" << endl;
    cout << "Computer Maintenance Level: " << userPlayer.getCompMaintLvl() << "%" << endl;
    cout << "Computer Virus: " << userPlayer.getCompVirus() << endl;
    cout << "Antivirus: " << userPlayer.getAntiVirus() << endl;
    cout << "VPN(s): " << userPlayer.getVPN() << endl;
    cout << "Internet Provider Level: " << userPlayer.getIPL() << endl;
    cout << "Dogecoin: " << userPlayer.getDogeCoin() << endl;
    cout << "Frustration Level: " << userPlayer.getFrustrationLevel() << endl;
    cout << "Carmen's Progress: " << hacker.getProgressLevel() << endl;
    cout << "Hackers Defeated: " << hackersDefeated << endl;
    cout << endl;
    //userPlayer.displayMyCompParts();
    //cout << endl;
}

void Game::RPS(){
    cout << "ROCK PAPER SCISSORS!" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cin >> userRPC;
    cout << endl;

    if(userRPC == 1){ //Assigning 1 as rock
        cout << "Your choice is rock" << endl;
    }
    else if(userRPC == 2){ //Assigning 2 as paper
        cout << "Your choice is paper" << endl;
    }
    else if(userRPC == 3){ //Assigning 3 as scissor
        cout << "Your choice is scissors" << endl;
    }
    else{ //Anything that is not 1-3
        cout << "Invalid option! Choose again: ";
        cin >> userRPC;
        cout << endl;
            if(userRPC == 1){
                cout << "Your choice is rock" << endl;
            }
            else if(userRPC == 2){
                cout << "Your choice is paper" << endl;
            }
            else if(userRPC == 3){
                cout << "Your choice is scissors" << endl;
            }
    }

    srand(time(NULL));
    compRPC = rand() % 1 + 3; //Generating and assigning a random number between 1-3

    if(compRPC == 1){//Assigning 1 as rock
        cout << "Jason's choice is rock" << endl;
    }
    else if(compRPC == 2){ //Assigning 2 as paper
        cout << "Jason's choice is paper" << endl;
    }
    else if(compRPC == 3){ //Assigning 3 as scissor
        cout << "Jason's choice is scissors" << endl;
    }

    cout << endl;

    if(userRPC == compRPC){ //Computer and user have the same choice
        cout << "It's a tie!" << endl;
        cout << endl;
    }
    else if(userRPC == 1){ //If user's choice is rock
        if(compRPC == 2){ //If computer's choice is paper
            cout << "You lose!" << endl;
            cout << endl;
        }
        if(compRPC == 3){ //If computer's choice is scissors
            cout << "Congratulations, you won!" << endl;
            cout << endl;
            userPlayer.setFrustrationLevel((userPlayer.getFrustrationLevel() - 5)); //Updating the frustration level after winning
        }
    }
    else if(userRPC == 2){ //If user's choice is paper
        if(compRPC == 1){ //If computer's choice is rock
            cout << "Congratulations, you won!" << endl;
            cout << endl;
            userPlayer.setFrustrationLevel((userPlayer.getFrustrationLevel() - 5)); //Updating the frustration level after winning
        }
        if(compRPC == 3){ //If computer's choice is scissors
            cout << "You lose!" << endl;
            cout << endl;
        }
    }
    else{ //If user's choice is scissors
        if(compRPC == 1){ //If compuiter's choice is rock
            cout << "You lose!" << endl;
            cout << endl;
        }
        if(compRPC == 2){ //If computer's choice is paper
            cout << "Congratulations, you won!" << endl;
            cout << endl;
            userPlayer.setFrustrationLevel((userPlayer.getFrustrationLevel() - 5)); //Updating the frustration level after winning
        }
    }
}

void Game::endOfGameStats(){
    cout << "\t *End of Game Stats*" << endl;
    cout << "Player Name: " << userPlayer.getPlayerName() << endl;
    cout << "Computer Maintenance Level: " << userPlayer.getCompMaintLvl() << "%" << endl;
    cout << "Computer Virus: " << userPlayer.getCompVirus() << endl;
    cout << "Antivirus: " << userPlayer.getAntiVirus() << endl;
    cout << "VPN(s): " << userPlayer.getVPN() << endl;
    cout << "Internet Provider Level: " << userPlayer.getIPL() << endl;
    cout << "Dogecoin: " << userPlayer.getDogeCoin() << endl;
    cout << "Frustration Level: " << userPlayer.getFrustrationLevel() << endl;
    cout << "Carmen's Progress: " << hacker.getProgressLevel() << endl;
    cout << "Hackers Defeated: " << hackersDefeated << endl;
    cout << endl;
}