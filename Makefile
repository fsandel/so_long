# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 09:53:10 by fsandel           #+#    #+#              #
#    Updated: 2022/11/17 17:20:52 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= so_long.out
OBJ_DIR			= ./obj/
LIBFT_DIR		= ./libft/
LIBFT			= $(LIBFT_DIR)libft.a
OBJ_FILES		= $(SRC:.c=.o)
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MLX				= ./lib/MLX42/libmlx42.a
MLXFLAGS		= -lglfw -L "/Users/fsandel/.brew/opt/glfw/lib/"
HEADERS			=  -I ./include -I $(LIBMLX)/include
LIBMLX			=./MLX42


SRC				=	so_long.c so_long_backgound.c so_long_check.c \
					so_long_error.c so_long_flood.c so_long_loop.c \
					so_long_map.c so_long_map_1.c so_long_move.c \
					so_long_pickup.c so_long_player.c so_long_steps.c \
					so_long_utils.c so_long_enemy.c so_long_math.c \
					so_long_end.c so_long_directions.c \
					so_long_enemy_movement.c

HDR			=	settings.h so_long_structs.h so_long.h textures.h

$(OBJ_DIR)%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				@make lib
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLXFLAGS) $(HEADERS)

all:			$(NAME)

lib:
				@make -C libft

clean:
				make clean -C libft
				$(RM) $(OBJ)

fclean:			
				make clean
				make fclean -C libft
				$(RM) $(NAME)

re:
				make fclean
				make all

run:
				@make all
				@./$(NAME) map.ber

.PHONY:			all clean fclean re lib 
