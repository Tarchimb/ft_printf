# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/11/17 12:55:30 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

SRCS		=	./ft_printf.c			\
				./ft_putchar.c			\
				./ft_putstr.c			\
				./ft_putnbr.c			\
				./ft_putnbr_unsigned.c	\
				./ft_put_hexa.c			\


OBJS		=	${SRCS:.c=.o}

INCLUDES	=	./ft_printf.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		=	libftprintf.a

RM			=	rm -f

all:		${NAME}

.c.o:		${INCLUDES}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "${BLUE}BUILD${END} ${<:.c=.o}"

$(NAME):	${OBJS} ${INCLUDES}
			@ar rcs ${NAME} ${OBJS}
			@echo "${GREEN}CREATE${END} ${NAME}"

clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			@echo "${RED}DELETE${END} *.o"

fclean:		clean
			@${RM} ${NAME}
			@echo "${RED}DELETE${END} ${NAME}"

re:			fclean all

.PHONY: 	all clean fclean re
