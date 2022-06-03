# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 17:52:13 by sebonie           #+#    #+#              #
#    Updated: 2022/06/03 13:20:06 by sebonie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	base/so_long.c base/aux.c base/map_proc/map_init.c\
				base/map_proc/chars_player.c base/map_proc/map_validator.c\
				base/map_proc/walls.c base/game_init.c base/mlx_windownhooks.c\
				base/movement.c base/window_proc.c

NAME		=	so_long

HEADER		=	base/so_long.h

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

LIBFT		=	lib/lib42/libft.a
LIBFT_DIR	=	lib/lib42

MLXFLAGS	=	-L lib/mlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	lib/mlx

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			@make -s -C $(MLXDIR)
			@make -s -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS) -lm

%.o : %.c	$(HEADER)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus:
			$(MAKE) -C ./bonus


clean:
			$(RM) $(OBJS)
			$(MAKE) -C ./bonus clean

fclean:		clean
			$(RM) $(NAME)
			make fclean -s -C $(LIBFT_DIR)
			make clean -s -C $(MLXDIR)
			$(MAKE) -C ./bonus fclean

re:			fclean all

.PHONY:		all clean fclean re bonus