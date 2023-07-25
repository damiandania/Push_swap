# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dania <dania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/07/25 19:05:33 by dania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Includes
INC			= -I ./includes/

# Sources
SRC_DIR 	= src

SRC_FILES	=	main.c			\
		check_input.c	\
		init_stack.c	\
		utils_stack.c	\
		push_swap.c		\
		utils.c	

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))	

# Objects
OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

# Libft
LIBFT_DIR	= ./libft
LIBFT_PATH	= ${LIBFT_DIR}/libft.a

# Compilation info
CC	= gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall
LFLAGS:= -L $(LIBFT_DIR) -lft

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
PURPLE	= \033[0;35m
RESET	= \033[0m

all: $(NAME)

# Main rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Objects rule
$(NAME): $(OBJS)
	@make -C ${LIBFT_DIR} --no-print-directory
	@echo "$(PURPLE)Compiling push_swap...$(RESET)"
	@$(CC) $(OBJS) $(LFLAGS) -o $@
	@echo "$(GREEN)OK$(RESET)"

# Clean rules
clean:
	@make clean -C ${LIBFT_DIR} --no-print-directory
	@echo "$(RED)Deleting push_swap object...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)OK$(RESET)"

fclean: clean
	@make fclean -C ${LIBFT_DIR} --no-print-directory
	@echo "$(RED)Deleting push_swap executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)OK$(RESET)"

bonus: all

re: fclean all

.PHONY: all re clean fclean
