# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:01:21 by hiamedja          #+#    #+#              #
#    Updated: 2023/04/09 00:18:12 by hiamedja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#NAMEB = checker

PUSH_SWAP.SRC = main.c	ft_split.c	filling_stack.c	ft_atoi.c ft_substr.c ft_check_param.c	ft_error.c ft_sort.c	ft_swap_ab.c	ft_rotate_ab.c	ft_rrotate_ab.c	ft_push_ab.c ft_position.c \
	

#PUSH_SWAP_BONUS.SRC = \

CFLAGS = -Wall -Wextra -Werror

OBJ = $(PUSH_SWAP.SRC:.c=.o)
# OBJ = main.o ft_split.o filling_stack.o ft_atoi.o ft_substr.o ft_check_param.o ft_error.o ft_sort.o ft_swap_ab.o ft_rotate_ab.o ft_rrotate_ab.o ft_push_ab.o ft_position.o

#OBJ_BONUS = $(PUSH_SWAP_BONUS.SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

#$(NAMEB) : $(OBJ_BONUS)
#	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)

#bonus : $(NAMEB)

clean :
	$(RM) -rf $(OBJ)
#	$(RM) -rf $(OBJ_BONUS)

fclean : clean
	$(RM) -rf $(NAME)

re : fclean all