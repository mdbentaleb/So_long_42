# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 13:43:14 by moben-ta          #+#    #+#              #
#    Updated: 2025/03/23 15:46:08 by moben-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
YELLOW = \033[33m
RED='\033[31m'
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = ./MLX42/libmlx42.a
NAME = so_long
BNAME = so_long_bonus
PRTFLIB = ft_printf/libftprintf.a

SRCS = mandatory/so_long.c mandatory/utils/utils.c mandatory/utils/parsing.c \
		mandatory/utils/ft_split.c mandatory/utils/ft_game.c mandatory/utils/ft_game_utils.c \
		mandatory/utils/ft_check_valid_path.c mandatory/utils/ft_check_map_errors.c

SRCSB = bonus/so_long_bonus.c bonus/utils/utils_bonus.c bonus/utils/parsing_bonus.c \
		bonus/utils/ft_split_bonus.c bonus/utils/ft_itoa_bonus.c bonus/utils/ft_game_bonus.c \
		bonus/utils/ft_game_utils_bonus.c bonus/utils/ft_enmey_animation_bonus.c \
		bonus/utils/ft_check_valid_path_bonus.c bonus/utils/ft_check_map_errors_bonus.c

GNL = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

PRTFSRC = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr.c \
			ft_printf/ft_putp.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

OBJ = $(SRCS:%.c=%.o)
BNOBJ = $(SRCSB:%.c=%.o)
GNLOBJ = $(GNL:%.c=%.o)
PRTFOBJ = $(PRTFSRC:%.c=%.o)

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	LIBFLAGS = -Iinclude -L./MLX42/build -lmlx42 -L./MLX42/build -lglfw -L./ft_printf -lftprintf \
        -lGL -lm -lpthread -ldl
else ifeq ($(UNAME), Darwin)
	LIBFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -L./MLX42/ -lglfw3
endif

all: run_setup $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

$(NAME): $(OBJ) $(GNLOBJ) $(PRTFOBJ)
	@echo "$(YELLOW) Compiling so_long...$(RESET)"
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJ) $(GNLOBJ) $(PRTFLIB) $(MLX) -o $@

bonus: run_setup $(BNAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

$(BNAME): $(BNOBJ) $(GNLOBJ) $(PRTFOBJ)
	@echo "$(YELLOW) Compiling so_long_bonus...$(RESET)"
	$(CC) $(CFLAGS) $(LIBFLAGS) $(BNOBJ) $(GNLOBJ) $(PRTFLIB) $(MLX) -o $@

run_setup:
	@echo "$(YELLOW)🔧 Running setup...$(RESET)"
	@./archive_extractor.sh || { echo "$(RED)❌ Setup failed!$(RESET)"; exit 1; }

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line/get_next_line.o: get_next_line/get_next_line.c get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line/get_next_line_utils.o: get_next_line/get_next_line_utils.c get_next_line/get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

$(PRTFOBJ): ft_printf/%.o: ft_printf/%.c ft_printf/ft_printf.h
	@${MAKE} -C ft_printf

clean:
	@${MAKE} -C ft_printf clean
	rm -rf $(OBJ) $(BNOBJ) $(GNLOBJ)

fclean: clean
	@${MAKE} -C ft_printf fclean
	rm -rf $(NAME) $(BNAME)
	rm -rf MLX42

re: fclean all

.PHONY: clean
