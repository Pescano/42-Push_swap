# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 17:16:32 by paescano          #+#    #+#              #
#    Updated: 2023/07/07 12:21:37 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c utils/checkers.c utils/exit.c utils/handle_arguments.c \
		libft/ft_atoi.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_memmove.c \
		libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
		libft/ft_strlen.c movements/swap.c movements/push.c movements/rotate.c \
		movements/reverse_rotate.c sort/special_cases.c sort/radix.c 

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

AR = ar -src

all: ${NAME}

$(NAME): $(OBJS)
	${AR} ${NAME}.a ${OBJS}
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	${RM} ${OBJS} ${NAME}.a

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re