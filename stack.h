/* stack.h
    Edited by Chris Qiu, 8/10/2013
*/

#define MAX_LEN_STACK 14

struct stack
{
    int content[MAX_LEN_STACK];   // factor 
    int top;                      // index to top of the stack, point to a valid value
};

/* push a value into a stack*/
int stack_push(struct *pStack, int value)
{
    top++;
    pStack->content[pStack->top] = value;
    return 0;
}

/* pop the top value of the stack*/
int stack_pop(struct *pStack)
{
    if(pStack->top == -1)
    {
        return 1;
    }
    else
    {
        int iTemp = pStack->content[pStack->top];
        top--;
        return iTemp;
    }
}

/* clear stack*/
int stack_clear(stack *pSatck)
{
    int index = pSatck->top;
    for( ; index >= 0; index--)
    {
        stack_pop(pSatck);
    }
    // pSatck->top = -1;
    return 0;
}

/* pop multi value of stack*/
int stack_multi_pop(stack *pStack, stack *pSt_out, int iNum)
{
    stack_clear(pSt_out);
    int index = 0;
    for( ; index<iNum; index++)
    {
        stack_push( pSt_out, stack_pop(pStack->top) );
    }
    return 0;
}



