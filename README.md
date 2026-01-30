# cs121-lab4

Concept:
1. Automatically cycling horse race
2. Each horse has different odds
3. User can bet on horse races using real horse racing bet types

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
  float* payout {1st, 2nd, 3rd}
  float baseOdds
  float seededOdds
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

void clearBet(bet*) {
  sets bet to blank state
}

int main() {
  createGame();
}
