#include <stdio.h>
#include "deque.h"

void            display(unsigned int n, void *data)
{
  unsigned int	*nbr = (unsigned int *)(data);
  
  printf("n: [%d] data: [%d]\n", n, *nbr);
}

int		main()
{
  struct deque	new_deque;		
  unsigned int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int		i = 0;

  deque_init(&new_deque);

  printf("test1: push 5 elements (from 0 to 4) as a stack\n");
  for (i = 0; i < 5; ++i)
    new_deque.push_front(&new_deque, &tab[i]);
  new_deque.show(&new_deque, &display);
  printf("empty [0]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [5]:[%d]\n", new_deque.size(&new_deque));
  printf("front [4]:[%d]\n", *(unsigned int *)(new_deque.front(&new_deque)));
  printf("back [0]:[%d]\n", *(unsigned int *)(new_deque.back(&new_deque)));
  printf("----------\n\n");
 
  printf("test2: push 5 elements (from 5 to 9) as a queue\n");
  for (i = 5; i < 10; ++i)
    new_deque.push_back(&new_deque, &tab[i]);
  new_deque.show(&new_deque, &display);
  printf("empty [0]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [10]:[%d]\n", new_deque.size(&new_deque));
  printf("front [4]:[%d]\n", *(unsigned int *)(new_deque.front(&new_deque)));
  printf("back [9]:[%d]\n", *(unsigned int *)(new_deque.back(&new_deque)));
  printf("----------\n\n");

  printf("test3: pop 2 elements (from 0 to 2) at the top as a stack\n");
  for (i = 0; i < 2; ++i)
    new_deque.pop_front(&new_deque);
  new_deque.show(&new_deque, &display);
  printf("empty [0]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [8]:[%d]\n", new_deque.size(&new_deque));
  printf("front [2]:[%d]\n", *(unsigned int *)(new_deque.front(&new_deque)));
  printf("back [9]:[%d]\n", *(unsigned int *)(new_deque.back(&new_deque)));
  printf("----------\n\n");

  printf("test4: pop 2 elements (from 5 to 7) at the back as a queue\n");
  for (i = 0; i < 2; ++i)
    new_deque.pop_back(&new_deque);
  new_deque.show(&new_deque, &display);
  printf("empty [0]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [6]:[%d]\n", new_deque.size(&new_deque));
  printf("front [2]:[%d]\n", *(unsigned int *)(new_deque.front(&new_deque)));
  printf("back [7]:[%d]\n", *(unsigned int *)(new_deque.back(&new_deque)));
  printf("----------\n\n");

  printf("test5: pop 20 elements (from 0 to 6 and more) at the top as a queue\n");
  for (i = 0; i < 20; ++i)
    new_deque.pop_front(&new_deque);
  new_deque.show(&new_deque, &display);
  printf("empty [1]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [0]:[%d]\n", new_deque.size(&new_deque));
  printf("----------\n\n");

  printf("test6: push 10 elements (from 0 to 9) as a stack\n");
  for (i = 0; i < 10; ++i)
    new_deque.push_front(&new_deque, &tab[i]);
  new_deque.show(&new_deque, &display);
  printf("empty [0]:[%d]\n", new_deque.empty(&new_deque));
  printf("size [10]:[%d]\n", new_deque.size(&new_deque));
  printf("front [9]:[%d]\n", *(unsigned int *)(new_deque.front(&new_deque)));
  printf("back [0]:[%d]\n", *(unsigned int *)(new_deque.back(&new_deque)));
  printf("----------\n\n");

  deque_destroy(&new_deque);
  return (0);
}
