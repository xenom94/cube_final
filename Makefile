NAME		=	cub3d
CC		=	cc
CFLAGS		=	-Imlx_linux -Werror -Wextra -Wall
RM		=	rm -rf
SRCS		=	main.c srcs/parsing/check_map.c srcs/parsing/exit.c srcs/parsing/get_data.c \
			srcs/parsing/get_map.c srcs/parsing/init_game.c srcs/parsing/init_texture.c \
			srcs/parsing/utils.c srcs/parsing/utils1.c srcs/raycasting/2dmap.c srcs/raycasting/cast_all_rays.c \
			srcs/raycasting/events_handler.c srcs/raycasting/init_player.c srcs/raycasting/mlx_utils.c srcs/raycasting/raycasting.c \
			srcs/raycasting/raypara.c
OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) -lmlx -lX11 -lXext -lm -lz $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
