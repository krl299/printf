SRCS	=	ft_printf.c	ft_parsers.c	ft_handles.c	ft_prints.c	ft_specs.c	ft_t_utils.c	ft_utils.c	ft_utils_2.c	ft_strlen.c	ft_strdup.c

OBJS	=	${SRCS:.c=.o}

NAME	= libftprintf.a

.c.o:
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -r ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

try:	${OBJS}
	gcc ${OBJS} && ./a.out
	
.PHONY: all fclean clean re try
