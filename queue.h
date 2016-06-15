#ifndef QUEUE_H_
# define QUEUE_H_

# include		"list.h"

typedef struct		queue {
  /* Properties */
  struct list		list;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push)(struct queue *self, void *data);
  void			(*pop)(struct queue *self);
  void			(*clear)(struct queue *self);

  /* --- Element access --- */
  void *		(*front)(struct queue *self);
  void *		(*back)(struct queue *self);

  /* --- Capacity --- */
  unsigned int		(*size)(struct queue *self);
  unsigned int		(*empty)(struct queue *self);

  /* --- Debug --- */
  void			(*show)(struct queue *self, void(*display)(unsigned int n, void *data));
}			queue;

struct queue *		new_queue(void);
void			queue_init(struct queue *self);
void			queue_destroy(struct queue *self);

#endif /* QUEUE_H_ */
