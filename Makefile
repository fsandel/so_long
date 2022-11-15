# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 09:53:10 by fsandel           #+#    #+#              #
#    Updated: 2022/11/15 15:33:29 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
RM				= rm -f
CFLAGS			= #-Wall -Wextra -Werror
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


SRC				= so_long.c so_long_utils.c so_long_map.c so_long_error.c so_long_flood.c

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
