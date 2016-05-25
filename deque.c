#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push_front(struct deque *th, void *data);
static void		push_back(struct deque *th, void *data);
static void		pop_front(struct deque *th);
static void		pop_back(struct deque *th);
static void		insert(struct deque *th, unsigned int n, void *data);
static void		erase(struct deque *th, unsigned int n);
static void		clear(struct deque *th);

/* --- Element access --- */
static void *		front(struct deque *th);
static void *		back(struct deque *th);
static void *		at(struct deque *th, unsigned int n);

/* --- Capacity --- */
static unsigned int	size(struct deque *th);
static unsigned int	empty(struct deque *th);

/* --- Debug --- */
static void		show(struct deque *th, void (*display)(unsigned int n, void *data));

/* Private functions declaration */
static void		init_properties(struct deque *th);
static void		init_method_ptr(struct deque *th);
static struct node *	create_node(void *data);
static struct node *	get_node_at(struct node *node, unsigned int n);
static void		delete_node(struct deque *th, struct node *node);

/* Constructor */
struct deque *          new_deque(void)
{
  struct deque		*new_deque;

  if ((new_deque = (struct deque *)malloc(sizeof(struct deque))) != NULL)
    deque_init(new_deque);
  return (new_deque);
}

void                    deque_init(struct deque *th)
{
  if (th != NULL)
    {
      init_properties(th);
      init_method_ptr(th);
    }
}

/* Destructor */
void                    deque_destroy(struct deque *th)
{
  if (th != NULL)
    {
      th->clear(th);
      init_properties(th);
    }
}

/* Methods */

/* --- Modifiers --- */
static void		push_front(struct deque *th, void *data)
{
  struct node		*new_node;

  if (th != NULL && (new_node = create_node(data)) != NULL)
    {
      if (th->head != NULL)
	{
	  new_node->next = th->head;
	  th->head->prev = new_node;
	}
      else
	th->end = new_node;
      th->head = new_node;
      th->len++;
    }
}

static void		push_back(struct deque *th, void *data)
{
  struct node		*new_node;

  if (th != NULL && (new_node = create_node(data)) != NULL)
    {
      if (th->end != NULL)
	{
	  new_node->prev = th->end;
	  th->end->next = new_node;
	}
      else
	th->head = new_node;
      th->end = new_node;
      th->len++;
    }
}

static void		pop_front(struct deque *th)
{
  if (th != NULL && th->head != NULL)
    delete_node(th, th->head);
}

static void		pop_back(struct deque *th)
{
  if (th != NULL && th->end != NULL)
    delete_node(th, th->end);
}

static void		insert(struct deque *th, unsigned int n, void *data)
{
  struct node		*new_node;
  struct node		*it;
  unsigned int		i;

  if (th != NULL)
    {
      if (n == 0)
	th->push_front(th, data);
      else if (n >= th->size(th))
	th->push_back(th, data);
      else
	{
	  it = get_node_at(th->head, n - 1);
	  if ((new_node = create_node(data)) != NULL)
	    {
	      new_node->prev = it;
	      new_node->next = it->next;
	      if (it->next != NULL)
		it->next->prev = new_node;
	      it->next = new_node;
	      th->len++;
	    }
	}
    }
}

static void		erase(struct deque *th, unsigned int n)
{
  struct node		*node;

  if (th != NULL)
    {
      node = get_node_at(th->head, n);
      printf("**********\n ---> Debug: [%d]\n**********\n", *(unsigned int *)(node->data));
      delete_node(th, node);
    }
}

static void		clear(struct deque *th)
{
  if (th != NULL)
    {
      while (th->head)
	delete_node(th, th->head);
    }
}

/* --- Element access --- */
static void *		front(struct deque *th)
{
  if (th != NULL && th->head != NULL)
    return (th->head->data);
  return (NULL);
}

static void *		back(struct deque *th)
{
  if (th != NULL && th->end != NULL)
    return (th->end->data);
  return (NULL);
}

static void *		at(struct deque *th, unsigned int n)
{
  struct node		*it;
  unsigned int		i;

  if (th != NULL)
    {
      it = th->head;
      i = 0;
      while (it->next != NULL && i < n)
	{
	  it = it->next;
	  i++;
	}
      return (it->data);
    }
  return (NULL);
}

/* --- Capacity --- */
static unsigned int	size(struct deque *th)
{
  if (th != NULL)
    return (th->len);
  return (0);
}

static unsigned int	empty(struct deque *th)
{
  if (th != NULL && th->len == 0)
    return (1);
  return (0);
}

/* --- Debug --- */
static void		show(struct deque *th, void (*display)(unsigned int n, void *data))
{
  struct node		*it;
  unsigned int		i;

  if (th != NULL)
    {
      it = th->head;
      i = 0;
      while (it != NULL)
	{
	  display(i, it->data);
	  it = it->next;
	  i++;
	}
    }
}

/* Private functions */
static void		init_properties(struct deque *th)
{
  if (th != NULL)
    {
      th->len = 0;
      th->head = NULL;
      th->end = NULL;
    }
}

static void		init_method_ptr(struct deque *th)
{
  if (th != NULL)
    {
      th->push_front = &push_front;
      th->push_back = &push_back;
      th->pop_front = &pop_front;
      th->pop_back = &pop_back;
      th->insert = &insert;
      th->erase = &erase;
      th->clear = &clear;
      th->front = &front;
      th->back = &back;
      th->at = at;
      th->size = &size;
      th->empty = &empty;
      th->show = &show;
    }
}

static struct node *	create_node(void *data)
{
  struct node		*new_node;

  if ((new_node = (struct node *)malloc(sizeof(struct node))) != NULL)
    {
      new_node->data = data;
      new_node->prev = NULL;
      new_node->next = NULL;
    }
  return (new_node);
}

static struct node *	get_node_at(struct node *node, unsigned int n)
{
  struct node		*it;
  unsigned int		i;

  if (node != NULL)
    {
      it = node;
      i = 0;
      while (it->next != NULL && i < n)
	{
	  it = it->next;
	  i++;
	}
      return (it);
    }
  return (NULL);
}

static void		delete_node(struct deque *th, struct node *node)
{
  struct node           *it;

  if (node != NULL)
    {
      it = node;
      if (node->prev != NULL)
	node->prev->next = node->next;
      else
	th->head = node->next;
      if (node->next != NULL)
	  node->next->prev = node->prev;
      else
	th->end = node->prev;
      free(it);
      th->len--;
    }
}
