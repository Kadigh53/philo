# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:02:40 by aaoutem-          #+#    #+#              #
#    Updated: 2023/06/08 13:37:09 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc 
RM = rm 
FLAGS = -Wall -Wextra -pthread -g  #-fsanitize=thread

SRC = main.c \
	init.c \
	utile_fcts/ft_atoi.c \
	utile_fcts/ft_calloc.c \
	utile_fcts/ft_gettime.c \
	utile_fcts/ft_msleep.c \

OBJ_F = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${OBJ_F} -o $@

%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@

clean :
	${RM} ${OBJ_F}
	
fclean : clean 
	${RM} ${NAME}

re : fclean ${NAME}

.PHONY : re all clean fclean

# SRC = main.c \
# 	init.c \
# 	utile_fcts/ft_atoi.c \
# 	utile_fcts/ft_calloc.c \
# 	utile_fcts/ft_gettime.c \
# 	utile_fcts/ft_msleep.c \

# OBJ_F = ${SRC:.c=.o}

# all : ${NAME}

# ${NAME} : ${OBJ_F}
# 	${CC} ${FLAGS} ${OBJ_F} -o $@

# %.o : %.c 
# 	${CC} ${FLAGS} -c $< -o $@

# clean :
# 	${RM} ${OBJ_F}
	
# fclean : clean 
# 	${RM} ${NAME}

# re : fclean ${NAME}



# SRC = main.c \
# 	init.c \
# 	utile_fcts/ft_atoi.c \
# 	utile_fcts/ft_calloc.c \
# 	utile_fcts/ft_gettime.c \
# 	utile_fcts/ft_msleep.c \

# OBJ_F = ${SRC:.c=.o}

# all : ${NAME}

# ${NAME} : ${OBJ_F}
# 	${CC} ${FLAGS} ${OBJ_F} -o $@

# %.o : %.c 
# 	${CC} ${FLAGS} $< -o $@

# clean :
# 	${RM} ${OBJ_F}
	
# fclean : clean 
# 	${RM} ${NAME}

# re : fclean ${NAME}

# .PHONY : re all clean fclean