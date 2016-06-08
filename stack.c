#include <stdlib.h>
#include "stack.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push(struct stack *that, void *data);
static void		pop(struct stack *that);
static void		clear(struct stack *that);

/* --- Element access --- */
static void *		top(struct stack *that);

/* --- Capacity --- */
static unsigned int	size(struct stack *that);
static unsigned int	empty(struct stack *that);

/* --- Debug --- */
static void		show(struct stack *that, void (*display)(unsigned int n, void *data));

/* Private functions declaration */
static void		init_properties(struct stack *that);
static void		init_methatod_ptr(struct stack *that);

/* Constructor */
struct stack *		new_stack(void)
{
  struct stack		*new_stack;

  if ((new_stack = (struct stack *)malloc(sizeof(struct stack))) != NULL)
    stack_init(new_stack);
  return (new_stack);
}

void                    stack_init(struct stack *that)
{
  if (that != NULL)
    {
      init_properties(that);
      init_methatod_ptr(that);
    }
}

/* Destructor */
void                    stack_destroy(struct stack *that)
{
  if (that != NULL)
    {
      that->clear(that);
      init_properties(that);
    }
}

/* Methatods */
/* --- Modifiers --- */
static void		push(struct stack *that, void *data)
{
  if (that != NULL)
    that->list->push_front(that->list, data);
}

static void		pop(struct stack *that)
{
  if (that != NULL)
    that->list->pop_front(that->list);
}

static void		clear(struct stack *that)
{
  if (that != NULL)
    that->list->clear(that->list);
}

/* --- Element access --- */
static void *		top(struct stack *that)
{
  if (that != NULL)
    return (that->list->front(that->list));
}

/* --- Capacity --- */
static unsigned int	size(struct stack *that)
{
  if (that != NULL)
    return (that->list->size(that->list));
}

static unsigned int	empty(struct stack *that)
{
  if (that != NULL)
    return (that->list->empty(that->list));
}

/* --- Debug --- */
static void		show(struct stack *that, void (*display)(unsigned int n, void *data))
{
  if (that != NULL && display != NULL)
    that->list->show(that->list, display);
}

/* Private functions */
static void		init_properties(struct stack *that)
{
  if (that != NULL)
    th->list = new_list();
}

static void		init_methatod_ptr(struct stack *that)
{
  if (that != NULL)
    {
      that->push = &push_front;
      that->pop = &pop_front;
      that->clear = &clear;
      that->top = &top;
      that->size = &size;
      that->empty = &empty;
      that->show = &show;
    }
}
