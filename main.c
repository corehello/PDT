#include "queue.h"
#include "stack.h"
#include <math.h>
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

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
  int iFirst[CARDSNUM/2];
  int iSecond[CARDSNUM/2];
  memcpy(iFirst, iCards, CARDSNUM/2*sizeof(int));
  memcpy(iSecond, iCards + arrlen/2, CARDSNUM/2*sizeof(int));
  queue_npush(qPlayer1, iFirst, sizeof iFirst / sizeof *iFirst);
  queue_npush(qPlayer2, iSecond, sizeof iSecond / sizeof *iSecond);

  // start the game
  printf("start the game: \n");
  display(qPlayer1, qPlayer2, sPipe);
  
  int flag = 1;
  int cast;
  while(queue_len(qPlayer1)*queue_len(qPlayer2)>0)
  {
    int alist[14];
    int len_alist;
    if (flag == 1)
    {
      cast = qPlayer1->content[qPlayer1->front];
      queue_pop(qPlayer1);
      // check if cast is in sPipe
      if (!stack_isin(sPipe, cast))
      {
        stack_push(sPipe, cast);
        flag = 2;
      }
      else
      {
        len_alist = stack_npop(sPipe, cast, alist);
        queue_npush(qPlayer1, alist, len_alist);
        flag = 1;
      }
      display(qPlayer1, qPlayer2, sPipe);
    }
    
    if (flag == 2)
    {
      cast = qPlayer2->content[qPlayer2->front];
      queue_pop(qPlayer2);
      if (!stack_isin(sPipe, cast))
      {
        stack_push(sPipe, cast);
        flag = 1;
      }
      else
      {
        len_alist = stack_npop(sPipe, cast, alist);
        queue_npush(qPlayer2, alist, len_alist);
        flag = 2;
      }
      display(qPlayer1, qPlayer2, sPipe);
    }
    
  }
  printf("Game over!");
  return 0;
}

/* display the result.*/
void display(Queue *qPlayer1, Queue *qPlayer2, Stack *sPipe)
{
    int i;
    // Player1
    printf("Player1: ");
    i = qPlayer1->front;
    for (; i < qPlayer1->front+qPlayer1->length ; i++ )
    {
        printf("%d ", qPlayer1->content[i]);
    }
    fflush(stdout);
    printf("\n");
    
    // Pipe
    printf("Pipe:    ");
    i = 0;
    for (; i <= sPipe->top; i++ )
    {
        printf("%d ", sPipe->content[i]);
    }
    fflush(stdout);
    printf("\n");
    
    // Player2
    printf("Player2: "); 
    i = qPlayer2->front;
    for (; i < qPlayer2->front+qPlayer2->length ; i++ )        
    {
         printf("%d ", qPlayer2->content[i]); 
    }
    fflush(stdout);
    printf("\n");
    printf("\n");
    sleep(2); 
}
