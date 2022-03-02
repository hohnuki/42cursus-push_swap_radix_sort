
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCLUDES = includes
SRCS_PATH = ./srcs/
LIBFT_PATH = ./libft/

SRCS = $(SRCS_PATH)main.c $(SRCS_PATH)stack_debug.c $(SRCS_PATH)sort_case_over7.c \
		$(SRCS_PATH)operation_rotate.c $(SRCS_PATH)operation_push.c $(SRCS_PATH)sort_case_3.c \
		$(SRCS_PATH)sort_case_2.c $(SRCS_PATH)operation_swap.c $(SRCS_PATH)free.c \
		$(SRCS_PATH)operation_reverse_rotate.c $(SRCS_PATH)sort_case_under_6.c $(SRCS_PATH)error_message.c \
		$(SRCS_PATH)ps_atoi.c
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