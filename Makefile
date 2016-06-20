NAME		= test_containers

SRCS_PATH	= ./sources/

INCS_PATH	= ./includes/

SRCS		+= test_containers.c
SRCS		+= $(SRCS_PATH)list.c
SRCS		+= $(SRCS_PATH)stack.c
SRCS		+= $(SRCS_PATH)queue.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS 		+= -Wextra -Wall -Werror
CFLAGS 		+= -ansi -pedantic
CFLAGS 		+= -I$(INCS_PATH)

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
