/* QUEUE.H
      Define queue as first in first out.
   Edited by Jay Jiang, corehello@gmail.com
             Chris Qiu, qwh005007@gmail.com 
*/

#define MAX_LEN_QUEUE 52

typedef struct Queue{
  int *content;
  int length;
  int front;  // Point to the first element. if queue is null, 0
  int rear;  // point to the last elements, if queue is null, -1
} Queue;

/* Create a queue */
void * queue_init()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->content = (int *)malloc(sizeof(int)*MAX_LEN_QUEUE);
  queue->length = 0;
  queue->front = 0;
  queue->rear = -1;
  return queue;
}

/* Insert an element into a queue */
void queue_push(Queue *queue, int element)
{
  /* If Queue is full */
  if (queue->length == MAX_LEN_QUEUE)
  {
    printf("Queue is full.\n");
  }
  else
  {
    queue->length++;
    if(++(queue->rear) == MAX_LEN_QUEUE)
    {
      queue->rear = 0;
    }
    queue->content[queue->rear] = element;
  }
  return;
}

/* Insert N-elements into a queue */
void queue_npush(Queue *queue, int *arr, size_t n)
{
  if (n > 0)
  {
    size_t i = 0;
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
