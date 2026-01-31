# cs121-lab4

Concept:
1. Automatically cycling horse race
2. Each horse has different odds
3. User can bet on horse races using real horse racing bet types

--------------------------------------------------------------------------------------------------------------------------------------------------
NOTICE
Gambling has been delayed. I'm sorry :(
--------------------------------------------------------------------------------------------------------------------------------------------------


enum name { 0, 1, 2, 3, 4 }
enum betType { win, place, exacta, quinella, trifecta, hi-5 }
/**
  Win = 1st
  Place = In top 2
  Exacta = 1st and 2nd in order
  Quinella = 1st 2nd any order
  Trifecta = top 3 in order
  Hi-5 = top 5
*/

Struct horse {
  name horseName
  float odds
  char path[15]
  int location
}

struct bet {
  enum type
  float wager
  horse*[5] ticket
}

struct user {
  float balance
  bet userBet
}

void printHorse(Horse* horse) {
  15 char line
}

void horseTurn(Horse* horse) {
  rng 1 - 100
    under odds
      heads
      update position
    over odds
      tails
  printHorse()
}

void horseRace(Horse* horseArray[5]) {
  Set/reset horses
  orderArray[5] to keep finishing order
  
  printHorse(all)

  while(not all horses have finished) {
    for (every horse) {
      horseTurn(horse)
      if horse finishes {
        store in orderArray[finishing place]
      }
      printHorse
    }
    0.25s pause
  }
  Print place, horse, and turns x5
}

int main() {
  create horses
  create horseArray
  while (user say yes) {
    horseTurn
    if (turn over 100) {
      end program
    }
  }
}