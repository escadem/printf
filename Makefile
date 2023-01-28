# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescat-l <eescat-l@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:11:56 by eescat-l          #+#    #+#              #
#    Updated: 2023/01/28 08:26:34 by eescat-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c \
			ft_uchar.c \
			ft_udecimal.c \
			ft_utils.c \
			ft_uunsigned.c 

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
