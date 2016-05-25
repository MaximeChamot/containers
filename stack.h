#ifndef _STACK_H_
# define _STACK_H_

# include "deque.h"

typedef struct		stack
{
  /* Properties: */
  struct deque		deque;
  
  /* Methods: */
  /* --- Modifiers --- */
  void			(*push)(struct stack *th, void *data);
  void			(*pop)(struct stack *th);
  void			(*clear)(struct deque *th);

  /* --- Element access --- */
  void *		(*top)(struct deque *th);

  /* --- Capacity --- */
  unsigned int		(*size)(struct stack *th);
  unsigned int		(*empty)(struct stack *th);

  /* --- Debug --- */
  void			(*show)(struct deque *th, void (*display)(unsigned int n, void *data));
}			stack;

struct deque *		new_stack(void);
void			stack_init(struct deque *th);
void			stack_destroy(struct deque *th);

#endif /* _STACK_H_ */
