# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:53:28 by ftholoza          #+#    #+#              #
#    Updated: 2023/12/21 15:12:00 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Werror -Wall -Wextra -ggdb
CC = cc
SRCS = $(addprefix srcs/, $(SRC))
SRC = pipes.c paths.c free.c ft_strncmp.c ft_strdup.c ft_substr.c ft_split.c ft_strjoin.c ft_memset.c ft_strlen.c ft_putstr_fd.c pipex.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h

re : fclean $(NAME)
$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -o pipex
$(OBJ) : $(SRCS)
	cc -c $(SRCS) -I pipex.h -g
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
