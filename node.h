#ifndef NODE_H_
# define NODE_H_

typedef struct		node
{
  void			*data;
  struct node		*prev;
  struct node		*next;
}			node;

#endif /* NODE_H_ */
