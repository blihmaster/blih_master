SRC	= ./blih_master.c

NAME    = blih_master

OBJS    = $(SRC:.c=.o)

RM      = rm -f

CC      = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
