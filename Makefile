# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 01:40:26 by aaoutem-          #+#    #+#              #
#    Updated: 2023/05/10 23:07:41 by kadigh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc 
FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
SRC = main.c \
	src/init.c \
	src/util_fcts/error.c \
	src/util_fcts/ft_atoi.c \
	src/util_fcts/ft_calloc.c \
	src/util_fcts/ft_strlen.c

OBJ_F = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${OBJ_F} -o philo

%.o : %.c 
	${CC} ${FLAGS} $< -c -o $@ 

clean :
	${RM} ${OBJ_F}

fclean : clean
	${RM} ${NAME} 

re : fclean all
