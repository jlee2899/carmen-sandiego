# Where is Carmen Sandiego?
C++ text-based adventure game based off the original video game "Where in the World is Carmen Sandiego?"
The mission is to defeat every hacker in each server room (total of 5) before the hackers steal all of the server's secret files.
The player will be able to buy supplies that will help their journey and can interact with NPCs, hackers, puzzles, etc.
The game utilizies a 2D map to represent player, shop, NPC, and locations.

# Running the Program
Step 1: Clone this repository by issuing the following command 

```
$ git clone https://github.com/jlee2899/carmen-sandiego.git
```
Step 2: Locate to directory

```
$ /carmen-sandiego/Carmen_Sandiego
```

Step 3: Compile by issuing the following command

```
$ g++ -std=c++11 carmen_sandiego.cpp Game.cpp Player.cpp Hacker.cpp BestBuy.cpp Map.cpp
```

# Note
This game was created using the very basics of C++ and OOP concepts
