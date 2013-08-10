/*#ifdef QUEUE_H */

#define MAX_LEN_QUEUE 52

struct queue{
  int content[MAX_LENGTH];
  int len;                  //valid value length= out>=in?out-in+1:out-in+52+1
  int in;                   //index to point where to insert
  int out;                  //index to point where to output
  
}

/*define a function to insert a value into a queue struct*/

int queue_in(struct *queue, int value)
{
  queue->content[queue->in] = value;
  in = mod(in-1, 52);
  queue->len++;
}

//int queue_multi_in(struct *queue, )

