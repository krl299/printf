SRCS	=	ft_printf.c

OBJS	=	${SRCS:.c=.o}

NAME	= libftprinf.a

.c.o:
	cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -r ${NAME} ${OBJS}

all:	${NAME}

bonus:	all

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all bonus fclean clean re
