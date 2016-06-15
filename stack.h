#ifndef _STACK_H_
# define _STACK_H_

# include		"list.h"

typedef struct		stack
{
  /* Properties */
  struct list		*list;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push)(struct stack *self, void *data);
  void			(*pop)(struct stack *self);
  void			(*clear)(struct stack *self);

  /* --- Element access --- */
  void *		(*top)(struct stack *self);

  /* --- Capacity --- */
  unsigned int		(*size)(struct stack *self);
  unsigned int		(*empty)(struct stack *self);

  /* --- Debug --- */
  void			(*show)(struct stack *self, void(*display)(unsigned int n, void *data));
}			stack;

struct stack *		new_stack(void);
void			stack_init(struct stack *self);
void			stack_destroy(struct stack *self);

#endif /* _STACK_H_ */
