# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:23:26 by zihirri           #+#    #+#              #
#    Updated: 2022/02/15 19:52:23 by zihirri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus 

CC = cc -lmlx -framework OpenGL -framework AppKit

RM = @rm -rf

CFLAGS = -Wall -Werror -Wextra 

FILES = ./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./map_maker/check_map.c \
		./map_maker/itoa.c \
		./map_maker/map-maker.c \
		./map_maker/so-long-utils.c \
		./moves/moves_extention.c \
		./moves/moves.c \
		./moves/ft_putnbr.c \
		so-long.c 
		
FILES_B = ./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./map_maker_bonus/check_map_bonus.c \
		./map_maker_bonus/itoa_bonus.c \
		./map_maker_bonus/map-maker_bonus.c \
		./map_maker_bonus/so-long-utils_bonus.c \
		./moves_bonus/moves_extention_bonus.c \
		./moves_bonus/moves_bonus.c \
		so-long-bonus.c \
		animation_bonus.c \
		print_animation.c 

# Colors
C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m


all : $(NAME)

$(NAME) : $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(NAME) 
	@echo "$(C_GREEN)[LIBRARY CREATED!]$(C_RES)"

bonus : $(NAME_B)

$(NAME_B) : $(FILES_B)
	$(CC) $(CFLAGS) $(FILES_B) -o $(NAME_B)
	@echo "$(C_L_BLUE)[BONUS CREATED!]$(C_RES)"


clean:
	${RM} so-long.o so-long-bonus.o
	@echo "$(C_RED)[OBJECT DELETED!]$(C_RES)"
	

fclean: clean
	${RM} so_long so_long_bonus
	@echo "$(C_RED)[PROJECT.A REMOVED!]$(C_RES)"

re: fclean all