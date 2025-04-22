SRCS = ft_putaddress.c \
    ft_putchar.c \
    ft_puthexalower.c \
    ft_puthexaupper.c \
    ft_putnbr.c \
    ft_putstr.c \
    ft_putunsigned.c \
    ft_printf.c \
    ft_printarg.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rsc

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
