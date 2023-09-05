# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/09/05 13:49:51 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Includes
INC			= -I ./includes/

# Sources
SRC_DIR 	= src

SRC_FILES	=	main.c			\
				check_input.c	\
				utils_stack.c	\
				big_sort.c		\
				utils_sort.c	\
				push_swap.c		\
				utils.c			\
				move_best.c		\
				move_swap.c		\
				move_push.c		\
				move_rotate.c	\
				move_reverse.c

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
GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m
ORANGE	=	\033[38;5;209m


all: $(NAME)

# Main rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Objects rule
$(NAME): $(OBJS)
	@make -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(GREEN)$(NAME)$(RESET): "
	@$(CC) $(OBJS) $(LFLAGS) -o $@
	@echo "$(GREEN) Ok ✓$(RESET)"

# Clean rules
clean:
	@make clean -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET): "
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)Ok $(RED)✗$(RESET)"

fclean: clean
	@make fclean -C ${LIBFT_DIR} --no-print-directory
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET): "
	@$(RM) $(NAME)
	@echo "$(GREEN)Ok $(RED)✗$(RESET)"

bonus: all

re: fclean all

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
