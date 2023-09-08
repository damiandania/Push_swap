# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:13:18 by ddania-c          #+#    #+#              #
#    Updated: 2023/09/08 18:40:35 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc

CFILE		=	ft_atoi.c 		\
				ft_bzero.c 		\
				ft_calloc.c 	\
				ft_isalnum.c 	\
				ft_isalpha.c 	\
				ft_isascii.c 	\
				ft_isdigit.c 	\
				ft_isprint.c 	\
				ft_itoa.c 		\
				ft_memchr.c 	\
				ft_memcmp.c 	\
				ft_memcpy.c 	\
				ft_memmove.c 	\
				ft_memset.c 	\
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c 	\
				ft_putstr_fd.c 	\
				ft_split.c 		\
				ft_strchr.c 	\
				ft_strdup.c 	\
				ft_striteri.c 	\
				ft_strjoin.c 	\
				ft_strlcat.c 	\
				ft_strlcpy.c 	\
				ft_strlen.c 	\
				ft_strmapi.c 	\
				ft_strncmp.c 	\
				ft_strnstr.c 	\
				ft_strrchr.c 	\
				ft_strtrim.c 	\
				ft_substr.c 	\
				ft_tolower.c 	\
				ft_strcmp.c		\
				ft_toupper.c 	\
				ft_lstnew.c 	\
				ft_lstadd_front.c\
				ft_lstsize.c 	\
				ft_lstlast.c 	\
				ft_lstadd_back.c\
				ft_lstdelone.c 	\
				ft_lstclear.c 	\
				ft_lstiter.c 	\
				ft_lstmap.c 	\
				ft_printf.c 	\
				ft_find_type.c	\
				ft_type_c.c		\
				ft_type_s.c		\
				ft_type_x.c		\
				ft_type_d.c		\
				ft_type_u.c		\
				ft_type_p.c		\
				get_next_line.c	\
				get_next_line_utils.c\

CFILE_DIR	=	./src/

SRC			=	$(addprefix $(CFILE_DIR), $(CFILE))

INC_DIR		=	./includes/

FLAG		=	-Wall -Wextra -Werror

INC			=	libft.h

OBJ			=	$(SRC:.c=.o)

GREEN	= \033[0;32m
WHITE	= \033[0;97m
RESET	= \033[0m
YELLOW	= \033[0;93m
RED		= \033[0;31m

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)[ok]✓$(RESET)"


clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET) "
	@rm -rf $(OBJ)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

fclean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	@rm -rf $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

re: fclean all

.PHONY: all clean fclean re
