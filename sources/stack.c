#include <stdlib.h>
#include "stack.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push(struct stack *self, void *data);
static void		pop(struct stack *self);
static void		clear(struct stack *self);

/* --- Element access --- */
static void *		top(struct stack *self);

/* --- Capacity --- */
static unsigned int	size(struct stack *self);
static unsigned int	empty(struct stack *self);

/* --- Debug --- */
static void		show(struct stack *self, void (*display)(unsigned int n, void *data));

/* Private functions declaration */
static void		init_properties(struct stack *self);
static void		init_method_ptr(struct stack *self);

/* Constructor */
struct stack *		new_stack(void)
{
  struct stack		*new_stack;

  if ((new_stack = (struct stack *)malloc(sizeof(struct stack))) != NULL)
    stack_init(new_stack);
  return (new_stack);
}

void                    stack_init(struct stack *self)
{
  if (self != NULL)
    {
      init_properties(self);
      init_method_ptr(self);
    }
}

/* Destructor */
void                    stack_destroy(struct stack *self)
{
  if (self != NULL)
    {
      list_destroy(&self->list);
      init_properties(self);
    }
}

/* Methods */
/* --- Modifiers --- */
static void		push(struct stack *self, void *data)
{
  if (self != NULL)
    self->list.push_front(&self->list, data);
}

static void		pop(struct stack *self)
{
  if (self != NULL)
    self->list.pop_front(&self->list);
}

static void		clear(struct stack *self)
{
  if (self != NULL)
    self->list.clear(&self->list);
}

/* --- Element access --- */
static void *		top(struct stack *self)
{
  if (self != NULL)
    return (self->list.front(&self->list));
  return (NULL);
}

/* --- Capacity --- */
static unsigned int	size(struct stack *self)
{
  if (self != NULL)
    return (self->list.size(&self->list));
  return (0);
}

static unsigned int	empty(struct stack *self)
{
  if (self != NULL)
    return (self->list.empty(&self->list));
  return (1);
}

/* --- Debug --- */
static void		show(struct stack *self, void (*display)(unsigned int n, void *data))
{
  if (self != NULL && display != NULL)
    self->list.show(&self->list, display);
}

/* Private functions */
static void		init_properties(struct stack *self)
{
  if (self != NULL)
    list_init(&self->list);
}

static void		init_method_ptr(struct stack *self)
{
  if (self != NULL)
    {
      self->push = &push;
      self->pop = &pop;
      self->clear = &clear;
      self->top = &top;
      self->size = &size;
      self->empty = &empty;
      self->show = &show;
    }
}
