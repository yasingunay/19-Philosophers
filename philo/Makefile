# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:24:50 by ygunay            #+#    #+#              #
#    Updated: 2023/01/27 12:23:21 by yasingunay       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c utils.c

OBJS = ${SRCS:.c=.o}

CC 	 = gcc -fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror 

NAME = philo

${NAME} : ${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : $(NAME)

clean: 
		rm -f ${OBJS}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
			
