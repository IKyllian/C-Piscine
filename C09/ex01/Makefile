# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdelport <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/23 10:11:25 by kdelport          #+#    #+#              #
#    Updated: 2020/10/28 09:22:21 by kdelport         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c \
		 srcs/ft_strcmp.c
OBJS  = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)	

re: fclean all
