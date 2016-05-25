#ifndef _QUEUE_H_
# define _QUEUE_H_

# include "deque.h"

typedef struct		queue
{
  /* Properties: */
  struct deque		deque;
  
  /* Methods: */
  /* --- Modifiers --- */
  void			(*push)(struct queue *th, void *data);
  void			(*pop)(struct queue *th);
  void			(*clear)(struct queue *th);

  /* --- Element access --- */
  void *		(*front)(struct queue *th);

  /* --- Capacity --- */
  unsigned int		(*size)(struct queue *th);
  unsigned int		(*empty)(struct queue *th);

  /* --- Debug --- */
  void			(*show)(struct queue *th, void (*display)(unsigned int n, void *data));
}			queue; 

struct queue *		new_stack(void);
void			stack_init(struct queue *th);
void			stack_destroy(struct queue *th);

#endif /* _QUEUE_H_ */
