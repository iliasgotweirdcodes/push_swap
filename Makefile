NAME = push_swap

NAME_BONUS = checker

HEADER = push_swap.h

HEADER_BONUS = push_swap_bonus.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = mandatory/push_swap.c mandatory/parsing.c mandatory/ft_split.c mandatory/ft_atoi.c \
		mandatory/ft_strjoin.c mandatory/ft_strlen.c mandatory/ft_strdup.c mandatory/free.c mandatory/list_tools.c \
		mandatory/ft_putstr.c mandatory/swap.c mandatory/push.c mandatory/rotate.c mandatory/revrotate.c \
		mandatory/sort.c mandatory/sort2.c mandatory/sort_stack.c mandatory/algorithm.c
SRCS_BONUS = bonus/checker_bonus.c bonus/parsing_bonus.c bonus/ft_split_bonus.c bonus/ft_atoi_bonus.c bonus/ft_strjoin_bonus.c bonus/ft_strlen_bonus.c \
			bonus/ft_strdup_bonus.c bonus/free_bonus.c bonus/list_tools_bonus.c bonus/ft_putstr_bonus.c bonus/swap_bonus.c \
			bonus/push_bonus.c bonus/rotate_bonus.c bonus/revrotate_bonus.c bonus/sort_bonus.c bonus/sort2_bonus.c \
		 	bonus/sort_stack_bonus.c bonus/algorithm_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
			bonus/checker_helpers_bonus.c bonus/ft_strcmp_bonus.c

OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

%.bonus.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
