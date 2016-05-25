#include <stdlib.h>
#include "deque.h"

/* Methods declaration */
/* --- Modifiers --- */
static void		push_front(struct deque *th, void *data);
static void		push_back(struct deque *th, void *data);
static void		pop_front(struct deque *th);
static void		pop_back(struct deque *th);
static void		insert(struct deque *th, unsigned int n, void *data);
static void		erase(struct deque *th, unsigned int start, unsigned int end);
static void		clear(struct deque *th);

/* --- Element access --- */
static void *		front(struct deque *th);
static void *		back(struct deque *th);
static void *		at(struct deque *th, unsigned int n);

/* --- Capacity --- */
static unsigned int	size(struct deque *th);
static unsigned int	empty(struct deque *th);

/* Private functions declaration */
static void		init_properties(struct deque *th);
static void		init_method_ptr(struct deque *th);

/* Constructor */
void                    deque_init(struct deque *th)
{
  if (th != NULL)
    {
      init_properties(th);
      init_method_ptr(th);
    }
}

struct deque *          new_deque(void)
{
  struct deque		*new_deque;

  if ((new_deque = (struct deque *)malloc(sizeof(struct deque))) != NULL)
    deque_init(new_deque);
  return (new_deque);
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
  if (th != NULL)
    {
    }
}

static void		push_back(struct deque *th, void *data)
{
  if (th != NULL)
    {
    }
}

static void		pop_front(struct deque *th)
{
  if (th != NULL)
    {
    }
}

static void		pop_back(struct deque *th)
{
  if (th != NULL)
    {
    }
}

static void		insert(struct deque *th, unsigned int n, void *data)
{
  if (th != NULL)
    {
    }
}

static void		erase(struct deque *th, unsigned int start, unsigned int end)
{
  if (th != NULL)
    {
    }
}

static void		clear(struct deque *th)
{
  if (th != NULL)
    {
    }
}

/* --- Element access --- */
static void *		front(struct deque *th)
{
  if (th != NULL)
    {
    }
}

static void *		back(struct deque *th)
{
  if (th != NULL)
    {
    }
}

static void *		at(struct deque *th, unsigned int n)
{
  if (th != NULL)
    {
    }
}

/* --- Capacity --- */
static unsigned int	size(struct deque *th)
{
  if (th != NULL)
    {
    }
}

static unsigned int	empty(struct deque *th)
{
  if (th != NULL)
    {
    }
}

/* Private functions */
static void		init_properties(struct deque *th)
{
  if (th != NULL)
    {
      th->len = 0;
      th->front = NULL;
      th->back = NULL;
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
    }
}
