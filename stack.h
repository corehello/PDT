#define MAX_LEN_STACK 14

struct stack
{
    int content[MAX_LEN_STACK];
    int top;        // index to top of the stack, point to a valid value
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
    if pStack->top == -1
    {
        return 1;
    }
    else
    {
        int iTemp = pStack -> top;
        top--;
        return iTemp;
    }
}
