#include <stdlib.h>
#include "queue.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push(struct queue *self, void *data);
static void		pop(struct queue *self);
static void		clear(struct queue *self);

/* --- Element access --- */
static void *		front(struct queue *self);
static void *		back(struct queue *self);

/* --- Capacity --- */
static unsigned int	size(struct queue *self);
static unsigned int	empty(struct queue *self);

/* --- Debug --- */
static void		show(struct queue *self, void (*display)(unsigned int n, void *data));

/* Private functions declaration */
static void		init_properties(struct queue *self);
static void		init_method_ptr(struct queue *self);

/* Constructor */
struct queue *		new_queue(void)
{
  struct queue		*new_queue;

  if ((new_queue = (struct queue *)malloc(sizeof(struct queue))) != NULL)
    queue_init(new_queue);
  return (new_queue);
}

void                    queue_init(struct queue *self)
{
  if (self != NULL)
    {
      init_properties(self);
      init_method_ptr(self);
    }
}

/* Destructor */
void                    queue_destroy(struct queue *self)
{
  if (self != NULL)
    {
      list_destroy(&self->list);
      init_properties(self);
    }
}

/* Methods */
/* --- Modifiers --- */
static void		push(struct queue *self, void *data)
{
  if (self != NULL)
    self->list.push_front(&self->list, data);
}

static void		pop(struct queue *self)
{
  if (self != NULL)
    self->list.pop_back(&self->list);
}

static void		clear(struct queue *self)
{
  if (self != NULL)
    self->list.clear(&self->list);
}

/* --- Element access --- */
static void *		front(struct queue *self)
{
  if (self != NULL)
    return (self->list.front(&self->list));
}

static void *		back(struct queue *self)
{
  if (self != NULL)
    return (self->list.back(&self->list));
}

/* --- Capacity --- */
static unsigned int	size(struct queue *self)
{
  if (self != NULL)
    return (self->list.size(&self->list));
}

static unsigned int	empty(struct queue *self)
{
  if (self != NULL)
    return (self->list.empty(&self->list));
}

/* --- Debug --- */
static void		show(struct queue *self, void (*display)(unsigned int n, void *data))
{
  if (self != NULL && display != NULL)
    self->list.show(&self->list, display);
}

/* Private functions */
static void		init_properties(struct queue *self)
{
  if (self != NULL)
    list_init(&self->list);
}

static void		init_method_ptr(struct queue *self)
{
  if (self != NULL)
    {
      self->push = &push;
      self->pop = &pop;
      self->clear = &clear;
      self->front = &front;
      self->back = &back;
      self->size = &size;
      self->empty = &empty;
      self->show = &show;
    }
}
