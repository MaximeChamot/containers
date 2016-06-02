#ifndef _NODE_H_
# define _NODE_H_

typedef struct		node
{
  void			*data;
  struct node		*prev;
  struct node		*next;
}			node;

#endif /* _NODE_H_ */
