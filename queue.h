/* QUEUE.H
      define queue as first in first out.
   Edited by Jay Jiang, corehello@gmail.com
             Chris Qiu, qwh005007@gmail.com 
*/

#define MAX_LEN_QUEUE 52

typedef struct Queue{
  int content[MAX_LEN_QUEUE];
  int length;
  int front; 
  int rear;
  
} Queue;

/* Insert an element into a queue */
void queue_push(Queue *queue, int element)
{
  /* If Queue is full, we cannot push an element into in */
  if (queue->length == MAX_LEN_QUEUE)
  {
    printf("Queue is full.\n");
  }
  else
  {
    queue->content[queue->rear] = element;
    if(++(queue->rear) == MAX_LEN_QUEUE)
    {
      queue->rear = 0;
    }
    queue->len++;
  }
  return;
}

/* Insert N-elements into a queue */
void queue_npush(struct *queue, int *arr)
{
  int n = sizeof arr / sizeof *arr;
  if (n > 0)
  {
    int i = 0;
    for ( ; i < n; i++)
    {
      queue_push(queue, arr[i]);
    }
  }
  return;
}

/* Pop front element of the queue */
void queue_pop(Queue *queue)
{
  if (queue->length == 0)
  {
    printf("queue is empty.\n");
  }
  else
  {
    if(++(queue->front) == MAX_LEN_QUEUE)
    {
      queue->front = 0;
    }
    queue->length--;
  }
  return;
}


/* Got queue length*/
int queue_len(Queue *queue)
{
  return queue->length;
}
