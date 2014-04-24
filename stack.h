/* STACK.H
     first in last out.
   Edited by Chris Qiu, 04/21/2014
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_STACK 14

typedef struct Stack
{
    int *content;
    int top;  // top index, if stack is null, -1
    int length;
} Stack;

/* Init stack */
void * stack_init()
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    pStack->content = (int *)malloc(sizeof(int)*MAX_LEN_STACK);
    pStack->top = -1;
    pStack->length = 0;
    return pStack;
}

/* Push an element into a stack */
void stack_push(Stack *pStack, int element)
{
    if (pStack->length == MAX_LEN_STACK)
    {
      printf("stack is full.\n");
    }
    else
    {
      pStack->length++;
      pStack->content[++pStack->top] = element;
    }
    return;
}

/* Pop the top element of the stack */
void stack_pop(Stack *pStack)
{
    if(pStack->top < 0)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        pStack->top--;
        pStack->length--;
    }
}

/* Get queue length*/
int stack_len(Stack *pStack)
{
  return pStack->length;
}

/* Based on item, find if there is another element equals 
   the item. If yes, pop all elements between them. else 
   return an array with -1.
 */
int stack_npop(Stack *pStack, int item, int *part)
{
    if(pStack->top < 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int i = pStack->top;
        for(; i >= 0; i--)
        {
            if(pStack->content[i] == item)
            {
                int len_part = pStack->top-i+2;
                memcpy(part, pStack->content+i, (pStack->top-i+1)*sizeof(int));
                part[pStack->top-i+1] = item;
                part[pStack->top-i+2] = -1;
                pStack->top = i-1;
                return len_part;;
            }
        }
    }
    // If none matches with item, then return a array with first element equals -1.
    *part = -1;
    return 1;
}

/* Check if cast is in pStack */
int stack_isin(Stack *pStack, int cast)
{
    if(pStack->top > -1)
    {
        int i = pStack->top;
        for (; i>=0 ;i-- )
        {
            if(pStack->content[i] == cast)
            {
                return 1;
            }
        }
    }
    return 0;
}

