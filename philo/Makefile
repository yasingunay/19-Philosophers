# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:24:50 by ygunay            #+#    #+#              #
#    Updated: 2023/02/09 17:41:21 by ygunay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c utils.c parsing.c philo_routine.c init.c

OBJS = ${SRCS:.c=.o}

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 


${NAME} : ${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : $(NAME)

clean: 
		rm -f ${OBJS}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
			
