#include <stdlib.h>
#include "list.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push_front(struct list *self, void *data);
static void		push_back(struct list *self, void *data);
static void		pop_front(struct list *self);
static void		pop_back(struct list *self);
static void		insert(struct list *self, unsigned int n, void *data);
static void		erase(struct list *self, unsigned int n);
static void		clear(struct list *self);

/* --- Element access --- */
static void *		front(struct list *self);
static void *		back(struct list *self);
static void *		at(struct list *self, unsigned int n);

/* --- Capacity --- */
static unsigned int	size(struct list *self);
static unsigned int	empty(struct list *self);

/* --- Debug --- */
static void		show(struct list *self, void (*display)(unsigned int n, void *data));

/* Private functions declaration */
static void		init_properties(struct list *self);
static void		init_method_ptr(struct list *self);
static struct node *	create_node(void *data);
static struct node *	get_node_at(struct node *node, unsigned int n);
static void		delete_node(struct list *self, struct node *node);

/* Constructor */
struct list *		new_list(void)
{
  struct list		*new_list;

  if ((new_list = (struct list *)malloc(sizeof(struct list))) != NULL)
    list_init(new_list);
  return (new_list);
}

void                    list_init(struct list *self)
{
  if (self != NULL)
    {
      init_properties(self);
      init_method_ptr(self);
    }
}

/* Destructor */
void                    list_destroy(struct list *self)
{
  if (self != NULL)
    {
      self->clear(self);
      init_properties(self);
    }
}

/* Methods */
/* --- Modifiers --- */
static void		push_front(struct list *self, void *data)
{
  struct node		*new_node;

  if (self != NULL && (new_node = create_node(data)) != NULL)
    {
      if (self->head != NULL)
	{
	  new_node->next = self->head;
	  self->head->prev = new_node;
	}
      else
	self->tail = new_node;
      self->head = new_node;
      self->len++;
    }
}

static void		push_back(struct list *self, void *data)
{
  struct node		*new_node;

  if (self != NULL && (new_node = create_node(data)) != NULL)
    {
      if (self->tail != NULL)
	{
	  new_node->prev = self->tail;
	  self->tail->next = new_node;
	}
      else
	self->head = new_node;
      self->tail = new_node;
      self->len++;
    }
}

static void		pop_front(struct list *self)
{
  if (self != NULL && self->head != NULL)
    delete_node(self, self->head);
}

static void		pop_back(struct list *self)
{
  if (self != NULL && self->tail != NULL)
    delete_node(self, self->tail);
}

static void		insert(struct list *self, unsigned int n, void *data)
{
  struct node		*new_node;
  struct node		*it;

  if (self != NULL)
    {
      if (n == 0)
	self->push_front(self, data);
      else if (n >= self->size(self))
	self->push_back(self, data);
      else
	{
	  it = get_node_at(self->head, n - 1);
	  if ((new_node = create_node(data)) != NULL)
	    {
	      new_node->prev = it;
	      new_node->next = it->next;
	      if (it->next != NULL)
		it->next->prev = new_node;
	      it->next = new_node;
	      self->len++;
	    }
	}
    }
}

static void		erase(struct list *self, unsigned int n)
{
  struct node		*node;

  if (self != NULL)
    {
      node = get_node_at(self->head, n);
      delete_node(self, node);
    }
}

static void		clear(struct list *self)
{
  if (self != NULL)
    {
      while (self->head)
	delete_node(self, self->head);
    }
}

/* --- Element access --- */
static void *		front(struct list *self)
{
  if (self != NULL && self->head != NULL)
    return (self->head->data);
  return (NULL);
}

static void *		back(struct list *self)
{
  if (self != NULL && self->tail != NULL)
    return (self->tail->data);
  return (NULL);
}

static void *		at(struct list *self, unsigned int n)
{
  struct node		*it;

  if (self != NULL && self->head != NULL)
    {
      it = get_node_at(self->head, n);
      if (it != NULL)
	return (it->data);
    }
  return (NULL);
}

/* --- Capacity --- */
static unsigned int	size(struct list *self)
{
  if (self != NULL)
    return (self->len);
  return (0);
}

static unsigned int	empty(struct list *self)
{
  if (self != NULL && self->len == 0)
    return (1);
  return (0);
}

/* --- Debug --- */
static void		show(struct list *self, void (*display)(unsigned int n, void *data))
{
  struct node		*it;
  unsigned int		i;

  if (self != NULL && display != NULL)
    {
      it = self->head;
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
static void		init_properties(struct list *self)
{
  if (self != NULL)
    {
      self->len = 0;
      self->head = NULL;
      self->tail = NULL;
    }
}

static void		init_method_ptr(struct list *self)
{
  if (self != NULL)
    {
      self->push_front = &push_front;
      self->push_back = &push_back;
      self->pop_front = &pop_front;
      self->pop_back = &pop_back;
      self->insert = &insert;
      self->erase = &erase;
      self->clear = &clear;
      self->front = &front;
      self->back = &back;
      self->at = at;
      self->size = &size;
      self->empty = &empty;
      self->show = &show;
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

  if (node != NULL)
    {
      it = node;
      while (it->next != NULL && n > 0)
	{
	  it = it->next;
	  n--;
	}
      return (it);
    }
  return (NULL);
}

static void		delete_node(struct list *self, struct node *node)
{
  struct node           *it;

  if (node != NULL)
    {
      it = node;
      if (node->prev != NULL)
	node->prev->next = node->next;
      else
	self->head = node->next;
      if (node->next != NULL)
	  node->next->prev = node->prev;
      else
	self->tail = node->prev;
      free(it);
      self->len--;
    }
}
