#ifndef _LIST_H_
# define _LIST_H_

# include "node.h"

typedef struct		list
{
  /* Properties: */
  unsigned int		len;
  struct node		*head;
  struct node		*end;

  /* Methods: */
  /* --- Modifiers --- */
  void			(*push_front)(struct list *th, void *data);
  void			(*push_back)(struct list *th, void *data);
  void			(*pop_front)(struct list *th);
  void			(*pop_back)(struct list *th);
  void			(*insert)(struct list *th, unsigned int n, void *data);
  void			(*erase)(struct list *th, unsigned int n);
  void			(*clear)(struct list *th);

  /* --- Element access --- */
  void *		(*front)(struct list *th);
  void *		(*back)(struct list *th);
  void *		(*at)(struct list *th, unsigned int n);

  /* --- Capacity --- */
  unsigned int		(*size)(struct list *th);
  unsigned int		(*empty)(struct list *th);

  /* --- Debug --- */
  void			(*show)(struct list *th, void (*display)(unsigned int n, void *data));
}			list;

struct list *		new_list(void);
void			list_init(struct list *th);
void			list_destroy(struct list *th);

#endif /* _DEQUE_H_ */
