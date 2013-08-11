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
  // all cards(need to be changed, it is not good here)
  int[CARDSNUM] iCards_init = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
  int[CARDSNUM] iCards_rand;
  cards_random(iCards_init, iCards_rand);
  
  // two players
  int index = 0;
  for ( ; index < CARDSNUM/2; index++)
  {
    queue_in(qPlayer1, iCards_rand[index]);
    queue_in(qPlayer2, iCards_rand[index+CARDSNUM/2]);
  }
  // start the game
  while(queue_len(qPlayer1)*queue_len(qPlayer2)>0)
  {
    // handout a card
    
    // 
  }
  return 0;
}

//  random the 52 cards
int cards_random(int[] cards_in, int[] cards_out)
{
  int index = 0;
  int iRand;
  for( ; index < CARDSNUM; index++)
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
  return 0;
}

