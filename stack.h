#ifndef _STACK_H_
# define _STACK_H_

# include		"list.h"

typedef struct		stack
{
  /* Properties */
  struct list		*list;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push)(struct stack *that, void *data);
  void			(*pop)(struct stack *that);
  void			(*clear)(struct stack *that);

  /* --- Element access --- */
  void *		(*top)(struct stack *that);

  /* --- Capacity --- */
  unsigned int		(*size)(struct stack *that);
  unsigned int		(*empty)(struct stack *that);

  /* --- Debug --- */
  void			(*show)(struct stack *that, void(*display)(unsigned int n, void *data));
}			stack;

struct stack *		new_stack(void);
void			stack_init(struct stack *that);
void			stack_destroy(struct stack *that);

#endif /* _STACK_H_ */
