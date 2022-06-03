# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 18:21:46 by sebonie           #+#    #+#              #
#    Updated: 2022/04/20 15:03:22 by sebonie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long_bonus.c aux_bonus.c map_proc/map_init_bonus.c\
				map_proc/chars_player_bonus.c map_proc/map_validator_bonus.c\
				map_proc/walls_bonus.c game_init_bonus.c mlx_windownhooks_bonus.c\
				movement_bonus.c window_proc_bonus.c\
				move_oppo.c

NAME		=	../so_long_bonus

HEADER		=	so_long_bonus.h

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

LIBFT		=	../lib/lib42/libft.a
LIBFT_DIR	=	../lib/lib42

MLXFLAGS	=	-L ../lib/mlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	../lib/mlx

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			@make -s -C $(MLXDIR)
			@make -s -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS) -lm

%.o : %.c	$(HEADER)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make fclean -s -C $(LIBFT_DIR)
			make clean -s -C $(MLXDIR)

re:			fclean all

.PHONY:		all clean fclean re