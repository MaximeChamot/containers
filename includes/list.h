#ifndef LIST_H_
# define LIST_H_

# include		"node.h"

typedef struct		list
{
  /* Properties */
  unsigned int		len;
  struct node		*head;
  struct node		*tail;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push_front)(struct list *self, void *data);
  void			(*push_back)(struct list *self, void *data);
  void			(*pop_front)(struct list *self);
  void			(*pop_back)(struct list *self);
  void			(*insert)(struct list *self, unsigned int n, void *data);
  void			(*erase)(struct list *self, unsigned int n);
  void			(*clear)(struct list *self);

  /* --- Element access --- */
  void *		(*front)(struct list *self);
  void *		(*back)(struct list *self);
  void *		(*at)(struct list *self, unsigned int n);

  /* --- Capacity --- */
  unsigned int		(*size)(struct list *self);
  unsigned int		(*empty)(struct list *self);

  /* --- Debug --- */
  void			(*show)(struct list *self, void (*display)(unsigned int n, void *data));
}			list;

struct list *		new_list(void);
void			list_init(struct list *self);
void			list_destroy(struct list *self);

#endif /* LIST_H_ */
