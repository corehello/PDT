#include "queue.h"
#include "stack.h"
#include <math.h>

#define CARDSNUM 52

int main(int ac, char *av[])
{
  // initial
  queue qPlayer1, qPlayer2;    // two player
  stack sShit, sContainor;     // the result and the temp containor to contain it
  
  // initial
  // all cards
  int[52] iCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
  cards_random(iCards, iCards);
  return 0;
}

//  random the 52 cards
int cards_random(int[] cards_in, int[] cards_out)
{
  int index = 0;
  int iRand;
  for( ; index < CARDSNUM, index++)
  {
    iRand = (int)((CARDSNUM-index)*random());
    cards_out[index] = cards_in[iRand];
    exchange(cards_in[iRand], cards_in[CARDSNUM-index-1]);
  }
  return 0;
}

// exchange two value
int exchange(int num1, int num2)
{
  num1 = num1 + num2;
  num2 = num1 - num2;
  num1 = num1 - num2;
}
