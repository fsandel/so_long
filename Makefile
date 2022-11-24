# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 09:53:10 by fsandel           #+#    #+#              #
#    Updated: 2022/11/24 17:49:39 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -lglfw -L "$(HOME)/.brew/opt/glfw/lib/"

OBJ_DIR			= ./obj/
OBJ_FILES		= $(SRC:.c=.o)
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_DIR		= libft
LIBFT_LIB		= libft.a
LIBFT			= $(LIBFT_DIR)/$(LIBFT_LIB)

MLX_DIR			= MLX
MLX_LIB			= libmlx42.a
MLX				= $(MLX_DIR)/$(MLX_LIB)

BREW			= rm -rf $(HOME)/.brew && git clone --depth=1 https://github.com/Homebrew/brew $(HOME)/.brew && echo 'export PATH=$(HOME)/.brew/bin:$(PATH)' >> $(HOME)/.zshrc && source $(HOME)/.zshrc && brew update

SRC				=	so_long.c so_long_backgound.c so_long_check.c \
					so_long_error.c so_long_flood.c so_long_loop.c \
					so_long_map.c so_long_move.c \
					so_long_pickup.c so_long_player.c so_long_steps.c \
					so_long_utils.c so_long_enemy.c so_long_math.c \
					so_long_end.c so_long_directions.c \
					so_long_enemy_movement.c so_long_enemy_list.c \
					so_long_check_map.c so_long_directions_diag.c \
					so_long_sprite_animation.c so_long_coin_counter.c

$(OBJ_DIR)%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		prepare $(OBJ)
				make -C $(LIBFT_DIR)
				make -C $(MLX_DIR)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLXFLAGS)

all:			$(NAME)

clean:
				$(RM) $(OBJ)
				make clean -C $(LIBFT_DIR)
				make clean -C $(MLX_DIR)

fclean:			
				$(RM) $(OBJ) $(NAME)
				make fclean -C $(LIBFT_DIR)
				make fclean -C $(MLX_DIR)

re:
				make fclean
				make all

run:
				@make all
				@./$(NAME) map.ber

libft:			
				git clone https://github.com/fsandel/libft $(LIBFT_DIR); make -C $(LIBFT_DIR)

mlx:
				git clone https://github.com/codam-coding-college/MLX42 $(MLX_DIR); make -C $(MLX_DIR)

make_mlx:		
				brew install glfw

check_brew:
ifeq ($(shell which brew),$(HOME)/.brew/bin/brew)
	@echo "Brew is installed"
else
	@echo "No Brew found"
	make install_brew
endif

check_glfw:
ifeq ($(shell brew info glfw | grep stable), ==> glfw: stable 3.3.8 (bottled), HEAD)
	@echo "current GLFW found"
else
	@echo "no current GLFW found"
	brew install glfw
endif

parrot:
				curl parrot.live

install_brew:
				$(shell $(BREW))

prepare:
				make check_brew
				make check_glfw
				make mlx
				make libft

.PHONY:			all clean fclean re lib 
