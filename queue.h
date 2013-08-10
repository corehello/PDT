/*#ifdef QUEUE_H */

#define MAX_LEN_QUEUE 52

struct queue{
  int content[MAX_LEN_QUEUE];
  int len;                  //valid value length= out>=in?out-in+1:out-in+52+1
  int in;                   //index to point where to insert
  int out;                  //index to point where to output
  
};

/*define a function to insert a value into a queue struct*/

int queue_in(struct *queue, int value)
{
  queue->content[queue->in] = value;
  in = mod(in-1, 52);
  queue->len++;
  return 0;
}

//int queue_multi_in(struct *queue, )

int queue_out(struct *queue)
{
  if (queue_len(queue) != 0)
  {
    int out_temp=out;
    out = mod(out-1, 52);
    queue->len--;
    return queue->content[out_temp];
  }
  else
  {
    printf("this is a empty queue, no value will be out, stupid boy!");
    return 1;
  }
}


/*function to got queue struct length*/
int queue_len(struct  *queue)
{
  return queue->len;
}
