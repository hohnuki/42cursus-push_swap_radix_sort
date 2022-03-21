CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCLUDES = includes
LIBFT_PATH = ./libft/

SRCS_FILES = main.c stack_debug.c sort_case_over_seven.c \
			operation_rotate.c operation_push.c sort_case_three.c \
			sort_case_two.c operation_swap.c free.c \
			operation_reverse_rotate.c sort_case_under_six.c error_message.c \
			ps_atoi.c check_duplicate.c compression_array.c \
			stack_argv.c is_sorted.c one_argument_to_array.c
SRCS		= $(addprefix ./srcs/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

LIBFTMAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG = -L$(LIBFT_PATH) -lft

all : $(NAME)

$(NAME) : $(OBJS)
		$(LIBFTMAKE)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAG) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		$(LIBFTMAKE) clean
		$(RM) $(OBJS)

fclean : clean
		$(LIBFTMAKE) fclean
		$(RM) $(NAME) $(SRCS_OBJS)

re : fclean all