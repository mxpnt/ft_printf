# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 09:02:45 by mapontil          #+#    #+#              #
#    Updated: 2021/11/23 12:36:01 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_utils.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_puthex.c
OBJS		=	$(addprefix srcs/, ${SRCS:.c=.o})
HEAD		=	includes/ft_printf.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a

%.o:			%.c ${HEAD}
				${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:		${OBJS} ${HEAD}
				ar -rc ${NAME} ${OBJS}
all:			${NAME} ${HEAD}
bonus:			${NAME} ${BONUS} ${BONUS_OBJS}
				ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}
clean:
				rm -f ${OBJS} ${BONUS_OBJS}
fclean:			clean
				rm -f ${NAME}
re:				fclean all
.PHONY:			all clean fclean re