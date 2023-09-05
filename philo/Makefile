NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS =	main.c \
		utils.c \
		parsing.c \

OBJC = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all