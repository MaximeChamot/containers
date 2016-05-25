#ifndef _DEQUE_H_
# define _DEQUE_H_

typedef struct		node
{
  void			*data;
  struct node		*next;
  struct node		*prev;
}			node;

typedef struct		deque
{
  /* Properties: */
  unsigned int		len;
  struct node		*front;
  struct node		*back;

  /* Methods: */
  /* --- Modifiers --- */
  void			(*push_front)(struct deque *th, void *data);
  void			(*push_back)(struct deque *th, void *data);
  void			(*pop_front)(struct deque *th);
  void			(*pop_back)(struct deque *th);
  void			(*insert)(struct deque *th, unsigned int n, void *data);
  void			(*erase)(struct deque *th, unsigned int start, unsigned int end);
  void			(*clear)(struct deque *th);

  /* --- Element access --- */
  void *		(*front)(struct deque *th);
  void *		(*back)(struct deque *th);
  void *		(*at)(struct deque *th, unsigned int n);

  /* --- Capacity --- */
  unsigned int		(*size)(struct deque *th);
  unsigned int		(*empty)(struct deque *th);
}			deque;

void			deque_init(struct deque *th);
struct deque *		new_deque(void);
void			deque_destroy(struct deque *th);

#endif /* _DEQUE_H_ */
