#ifndef _LIST_H_
# define _LIST_H_

# include		"node.h"

typedef struct		list
{
  /* Properties */
  unsigned int		len;
  struct node		*head;
  struct node		*tail;

  /* Methods */
  /* --- Modifiers --- */
  void			(*push_front)(struct list *that, void *data);
  void			(*push_back)(struct list *that, void *data);
  void			(*pop_front)(struct list *that);
  void			(*pop_back)(struct list *that);
  void			(*insert)(struct list *that, unsigned int n, void *data);
  void			(*erase)(struct list *that, unsigned int n);
  void			(*clear)(struct list *that);

  /* --- Element access --- */
  void *		(*front)(struct list *that);
  void *		(*back)(struct list *that);
  void *		(*at)(struct list *that, unsigned int n);

  /* --- Capacity --- */
  unsigned int		(*size)(struct list *that);
  unsigned int		(*empty)(struct list *that);

  /* --- Debug --- */
  void			(*show)(struct list *that, void (*display)(unsigned int n, void *data));
}			list;

struct list *		new_list(void);
void			list_init(struct list *that);
void			list_destroy(struct list *that);

#endif /* _LIST_H_ */
