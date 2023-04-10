# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:01:21 by hiamedja          #+#    #+#              #
#    Updated: 2023/04/10 00:46:30 by hiamedja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

PUSH_SWAP.SRC = \
	./mandatory/main.c				\
	./mandatory/main_utils.c		\
	./mandatory/ft_split.c			\
	./mandatory/filling_stack.c		\
	./mandatory/ft_atoi.c			\
	./mandatory/ft_substr.c			\
	./mandatory/ft_check_param.c	\
	./mandatory/ft_error.c			\
	./mandatory/ft_sort.c			\
	./mandatory/ft_swap_ab.c		\
	./mandatory/ft_rotate_ab.c		\
	./mandatory/ft_rrotate_ab.c		\
	./mandatory/ft_push_ab.c		\
	./mandatory/ft_position.c		\
	

PUSH_SWAP_BONUS.SRC = \
	./bonus/main.c					\
	./bonus/ft_split.c				\
	./bonus/filling_stack.c			\
	./bonus/ft_atoi.c				\
	./bonus/ft_substr.c				\
	./bonus/ft_check_param.c		\
	./bonus/ft_error.c				\
	./bonus/ft_swap_ab.c			\
	./bonus/ft_rotate_ab.c			\
	./bonus/ft_rrotate_ab.c			\
	./bonus/ft_push_ab.c			\
	./bonus/ft_position.c			\
	./bonus/checker.c 				\
	./bonus/get_next_line.c			\
	./bonus/get_next_line_utils.c	\


CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(PUSH_SWAP.SRC:.c=.o)
# OBJ = main.o ft_split.o filling_stack.o ft_atoi.o ft_substr.o ft_check_param.o ft_error.o ft_sort.o ft_swap_ab.o ft_rotate_ab.o ft_rrotate_ab.o ft_push_ab.o ft_position.o

OBJ_BONUS = $(PUSH_SWAP_BONUS.SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus :$(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAMEB)

clean :
	$(RM) -rf $(OBJ)
	$(RM) -rf $(OBJ_BONUS)

fclean : clean
	$(RM) -rf $(NAME)
	$(RM) -rf $(NAMEB)

re : fclean all