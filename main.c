#include "queue.h"
#include "stack.h"
#include <math.h>
#include "array.h"

#define CARDSNUM 52

int main(int ac, char *av[])
{
  void display(queue qPlayer1, queue qPlayer2, stack sPipe);
  // Initial:
  // 2 players
  queue qPlayer1, qPlayer2;    // two player
  // Result
  stack sPipe;     // the result and the temp containor to contain it
  
  // initial all cards
  int[CARDSNUM] iCards = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
  array_shuffle(iCards, queue_len(iCards));
  
  // distribute cards to 2 players.
  int index = 0;
  for ( ; index < CARDSNUM; index++)
  {
    queue_push(qPlayer1, iCards[index]);
    queue_push(qPlayer2, iCards[++index]);
  }

  // start the game
  int flag = 1;
  int cast;
  int[] alist;
  while(queue_len(qPlayer1)*queue_len(qPlayer2)>0)
  {
    if (flag == 1)
    {
      cast = queue_pop(qPlayer1);
      alist = stack_collect(cast, sPipe);
      if !alist
      {
        stack_multipush(sPipe, alist);
        flag = 2;
      }
      else
      {
        queue_multipush(qPlayer, alist);
        stack_pop(sPipe);
        flag = 1;
      }
    }
    if (flag == 2)
    {
      cast = queue_pop(qPlayer2);
      alist = collect(cast, sPipe);
      if !alist
      {
        stack_multipush(sPipe, alist);
        flag = 1;
      }
      else
      {
        queue_multipush(qPlayer2, alist);
        stack_pop(sPipe);
        flag = 2;
      }
    }
    array_clear(alist);
  }
  return 0;
}

/* display the result.*/
void display(queue qPlayer1, queue qPlayer2, stack sPipe)
{
  // update later. 
}
