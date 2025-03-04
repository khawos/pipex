# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 22:20:19 by adam              #+#    #+#              #
#    Updated: 2025/03/04 12:22:54 by amedenec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.

SRC_DIR = ./src
OBJ_DIR = ./obj
SRC = check_error.c exec.c init.c main.c path.c utils.c utils2.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all
