# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/07/11 18:05:10 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Includes
INC = -I ./includes/

# Sources
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils

SRC = $(SRC_DIR)/push_swap.c \
      $(UTILS_DIR)/utils.c \

# Objects
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

# Compilation info
CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

# Main rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Objects rule
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)OK$(RESET)\n"

# Clean rules
clean:
	@echo "$(RED)Deleting push_swap object...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)OK\n$(RESET)"

fclean: clean
	@echo "$(RED)Deleting push_swap executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)OK\n$(RESET)"

bonus: all

re: fclean all

.PHONY: all re clean fclean
