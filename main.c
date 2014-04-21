#include "queue.h"
#include "stack.h"
#include <math.h>
#include "array.h"

#define CARDSNUM 52

int main(int ac, char *av[])
{
  void display(Queue *qPlayer1, Queue *qPlayer2, Stack *sPipe);
  // Initial:
  // 2 players
  Queue *qPlayer1 = queue_init();
  Queue *qPlayer2 = queue_init();
  // Result
  Stack *sPipe = stack_init();
  
  // initial all cards
  int iCards[CARDSNUM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
  int arrlen = sizeof iCards / sizeof *iCards;
  array_shuffle(iCards, arrlen);
  
  // distribute cards to 2 players.
  int iFirst[CARDSNUM];
  memcpy(iFirst, iCards, CARDSNUM/2*sizeof(int));
  qPlayer1->content = iFirst;
  qPlayer2->content = iCards + arrlen/2;

  // start the game
  int flag = 1;
  int cast;
  while(queue_len(qPlayer1)*queue_len(qPlayer2)>0)
  {
    int *alist;
    if (flag == 1)
    {
      cast = queue_pop(qPlayer1);
      alist = stack_npop(sPipe, cast);
      if !alist
      {
        stack_npush(sPipe, alist);
        flag = 2;
      }
      else
      {
        queue_npush(qPlayer, alist);
        stack_pop(sPipe);
        flag = 1;
      }
    }
    if (flag == 2)
    {
      cast = queue_pop(qPlayer2);
      alist = stack_npop(sPipe, cast);
      if !alist
      {
        stack_npush(sPipe, alist);
        flag = 1;
      }
      else
      {
        queue_npush(qPlayer2, alist);
        stack_pop(sPipe);
        flag = 2;
      }
    }
  }
  return 0;
}

/* display the result.*/
void display(Queue *qPlayer1, Queue *qPlayer2, Stack *sPipe)
{
    // Player1
    printf("Player1: ");
    int i = qPlayer1->front;
    for (; i < qPlayer1->front+qPlayer1->length ; i++ )
    {
        printf("%d ", qPlayer1->content[i]);
    }
    printf("\n");
    
    // Pipe
    printf("Pipe:    ");
    int i = 0;
    for (; i <= sPipe->top; i++ )
    {
        printf("%d ", sPipe->content[i]);
    }
    print("\n");
    
    // Player2
    printf("Player2: "); 
    int i = qPlayer2->front;
    for (; i < qPlayer2->front+qPlayer2->length ; i++ )        
    {
         printf("%d ", qPlayer2->content[i]); 
    }
    printf("\n"); 
}
