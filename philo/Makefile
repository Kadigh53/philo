# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 01:40:26 by aaoutem-          #+#    #+#              #
#    Updated: 2023/06/23 14:35:42 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc 
RM = rm 
FLAGS = -Wall -Wextra -pthread
HEADER = philo.h
SRC = main.c \
	eat.c \
	sleep.c \
	parse.c \
	init.c \
	m_print.c \
	util_fcts/error.c \
	util_fcts/ft_atoi.c \
	util_fcts/ft_calloc.c \
	util_fcts/ft_gettime.c \
	util_fcts/ft_msleep.c \
	util_fcts/ft_strlen.c \
	

OBJ_F = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F} ${HEADER}
	${CC} ${FLAGS} ${OBJ_F} -o philo

%.o : %.c 
	${CC} ${FLAGS} $< -c -o $@

clean :
	${RM} ${OBJ_F}

fclean : 
	${RM} ${OBJ_F}
	${RM} ${NAME} 

re : fclean all

# .PHONY : re all clean fclean