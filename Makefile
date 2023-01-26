# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:11:56 by eescat-l          #+#    #+#              #
#    Updated: 2023/01/26 18:06:29 by eescat-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_digitutils.c \
	ft_printf.c \
	ft_puts.c \
	ft_utils.c 

OBJS = $(SRCS:.c=.o)


NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:       
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
