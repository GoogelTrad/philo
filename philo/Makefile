NAME = philo
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -f

SRCS =	main.c \
		utils.c \
		parsing.c \
		init_philo.c \
		routine.c \

OBJC = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -pthread -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all