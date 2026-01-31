#include <chrono>
#include <random>
#include <stdio.h>
#include <stdbool.h>
#include <thread>

// Slows down code for display purposes
#define pause std::this_thread::sleep_for(250ms)
#define longPause std::this_thread::sleep_for(1000ms)

#define TOTALHORSES 5

enum BetType {
    win,         // 1st Place
    place,       // Finish top 2
    show,        // Finish top 3
};

struct Horse {
    int horseName;              // Name (0, 1, 2, 3, 4)
    float flipOdds;             // Odds of a heads being flipped
    char path[15];              // 15 char race path
    int location;               // spot along the path
    // float payouts[3];        // amount given for win, place, show
};

struct horseOrderNode {
    Horse* thisHorsePtr;
    int time;
};

/**
 * TODO: Betting :)
struct Bet {
    enum BetType betType;
    float wager;
    Horse* ticket;
};


struct User {
    float balance;
    Bet bet;
};
*/

// HORSE FUNCTIONS

/**
 * Creates a 1 to 100 rng dist to allow for differing percentage chances per horse
 */
int flipCoinSeed() {
    static std::random_device rd;
    static std::uniform_int_distribution<int> dist(1, 100);
    return dist(rd);
}

/**
 * 
 */
void defineHorse(Horse* horse, int name, float flipOdds) {
    horse->horseName = name;
    horse->flipOdds = flipOdds;
    horse->path[0] = '0' + name;
    for (int i = 1; i < 15; i++) {
        horse->path[i] = '.';
    }
    horse->location = 0;
}

/**
 * Prints all 15 chars in a horse's path
 */
void printHorse(Horse* horse) {
    printf("\n");
    for (int i = 0; i < 15; i++) {
        printf("%c ", horse->path[i]);
    }
}

/**
 * Determins if a horse will move during its turn
 * Horse must generate below its flipOdds to move
 * @return if horse has reached end
 */
bool horseTurn(Horse* horse) {
    if (horse->location >= 14) {
        printf("\n- - -  F I N I S H E D  - - -");
        return true;
    }
    if (flipCoinSeed() < horse->flipOdds) {
        // Moves horse down path by 1
        horse->path[horse->location + 1] = horse->path[horse->location];
        horse->path[horse->location] = '.';
        horse->location++;
    }
    printHorse(horse);
    if(horse->location == 14) {
        return true;
    }
    return false;
}


void horseRace(int raceNumber, Horse* horseArray[5]) {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    // Introduction

    // Gives stats to each horse
    Horse* ptrHorse0 = horseArray[0];
    Horse* ptrHorse1 = horseArray[1];
    Horse* ptrHorse2 = horseArray[2];
    Horse* ptrHorse3 = horseArray[3];
    Horse* ptrHorse4 = horseArray[4];
    defineHorse(ptrHorse0, 0, 55);
    defineHorse(ptrHorse1, 1, 54);
    defineHorse(ptrHorse2, 2, 50);
    defineHorse(ptrHorse3, 3, 49);
    defineHorse(ptrHorse4, 4, 47);

    // Tracks the order of horses
    horseOrderNode orderArray[5];

    // Countdown
    printf("Race #%i begins in \n", raceNumber);
    pause;
    for (int i = 3; i > 0; i--) {
        printf("\n");
        printf("%i", i);
        longPause;
        printf("\n");
    }
    longPause;
    printf("\n");
    printf("GO!!!\n");
    pause;

    // Turn 0
    printHorse(ptrHorse0);
    printHorse(ptrHorse1);
    printHorse(ptrHorse2);
    printHorse(ptrHorse3);
    printHorse(ptrHorse4);
    printf("\n");
    pause;

    // Game continues until all horses finish
    bool finishStatuses[TOTALHORSES];
    for (int i = 0; i < TOTALHORSES; i++) {
        finishStatuses[i] = false;
    }
    int horsesFinished = 0;
    bool continueGame = true;

    // Turn Logic
    int turns = 0;
    bool hadFinishedBeforeTurn;
    while (continueGame) {
        turns++;
        pause;
        printf("\n");
        for (int i = 0; i < TOTALHORSES; i++) {
            // Figures out if it already finished
            if (finishStatuses[i]) {
                hadFinishedBeforeTurn = true;
            }
            else {
                hadFinishedBeforeTurn = false;
            }

            // Stores in finishing order
            finishStatuses[i] = horseTurn(horseArray[i]);
            if (finishStatuses[i] && !hadFinishedBeforeTurn) {
                orderArray[horsesFinished].thisHorsePtr = horseArray[i];
                orderArray[horsesFinished].time = turns;
                horsesFinished++;
            }
        }

        // Ends game once all finish
        if (horsesFinished == 5) {
            // Prints board one last time
            printf("\n");
            for (int i = 0; i < TOTALHORSES; i++) {
                finishStatuses[i] = horseTurn(horseArray[i]);
            }
            continueGame = false;
        }
        printf("\n");
        // Checks if all horses have finished
    }

    // Pints results
    printf("\nRESULTS:\n");
    pause;
    printf("1st: %i: %i turns\n", orderArray[0].thisHorsePtr->horseName, orderArray[0].time);
    pause;
    printf("2nd: %i: %i turns\n", orderArray[1].thisHorsePtr->horseName, orderArray[1].time);
    pause;
    printf("3rd: %i: %i turns\n", orderArray[2].thisHorsePtr->horseName, orderArray[2].time);
    pause;
    printf("4th: %i: %i turns\n", orderArray[3].thisHorsePtr->horseName, orderArray[3].time);
    pause;
    printf("5th: %i: %i turns\n", orderArray[4].thisHorsePtr->horseName, orderArray[4].time);
    pause;
    
}

int main(){
    // Start of game
    printf("\n");

    // Horses 0, 1, 2, 3, 4
    Horse horse0;
    Horse horse1;
    Horse horse2;
    Horse horse3;
    Horse horse4;
    Horse* ptrHorse0 = &horse0;
    Horse* ptrHorse1 = &horse1;
    Horse* ptrHorse2 = &horse2;
    Horse* ptrHorse3 = &horse3;
    Horse* ptrHorse4 = &horse4;

    // Use to itterate through horses in for statements
    Horse* horseArray[TOTALHORSES] = {ptrHorse0, ptrHorse1, ptrHorse2, ptrHorse3, ptrHorse4};
    int raceNumber = 0;
    bool playAgain = true;
    int playAgainChoice;
    while(playAgain) {
        raceNumber++;
        horseRace(raceNumber, horseArray);
        for (int i = 0; i < 100; i++) {
            printf("\nWould you like to race again? 0 - No | 1 - Yes ");
            scanf("%i", &playAgainChoice);
            switch (playAgainChoice) {
                case 0: // NO
                    printf("Play again some other time!\n");
                    return 0;
                case 1: // Yes
                    playAgain = true;
                    break;
                default: // Other
                    printf("Not a valid input");
                    playAgain = false;
            }
            if (playAgain) {
                break;
            }
            // Prevents infinite loop
            if (i == 100) {
                printf("Spam detected, ending program");
                return 0;
            }
        }
        // Infinite loop prevention
        if (raceNumber == 100) {
            printf("Dude go home. You have a problem.");
            return 0;
        }
    }
    return 0;
} // end main