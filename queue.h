#ifndef QUEUE_H_
# define QUEUE_H_

# include		"list.h"

typedef struct		queue {
  /* Properties */
  struct list		*list;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push)(struct stack *self, void *data);
  void			(*pop)(struct stack *self);
  void			(*clear)(struct stack *self);

  /* --- Element access --- */
  void *		(*front)(struct stack *self);
  void *		(*back)(struct stack *self);

  /* --- Capacity --- */
  unsigned int		(*size)(struct stack *self);
  unsigned int		(*empty)(struct stack *self);

  /* --- Debug --- */
  void			(*show)(struct stack *self, void(*display)(unsigned int n, void *data));
}

struct queue *		new_queue(void);
void			queue_init(struct queue *self);
void			queue_destroy(struct queue *self);

#endif /* QUEUE_H_ */
