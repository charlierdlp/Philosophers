   SRCS 	= srcs/main.c srcs/parser.c srcs/utils.c srcs/init.c srcs/death.c srcs/print_state.c
OBJS	= ${SRCS:.c=.o}
NAME	= philo
GCC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address

${NAME}:	${OBJS}
					${CC} ${CFLAGS} ${SRCS} -o philo

all:	${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re