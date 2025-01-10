NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c parsing.c ft_split.c ft_atoi.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_substr.c free.c list_tools.c\
		ft_putstr.c swap.c push.c rotate.c revrotate.c sort.c sort2.c sort_stack.c algorithm.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
