NAME = pipex

CC = cc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Werror

SRCS += test.c

SRCS_PATH = srcs/

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

INCLUDE = -I includes
LIBFT_INCUDE = -I ${LIBFT_PATH}/includes

vpath %.c ${SRCS_PATH}

OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE} ${LIBFT_INCUDE} ${LIBFT}

${OBJS_PATH}/%.o: %.c
	mkdir -p ${OBJS_PATH}
	${CC} ${CFLAGS} -c $^ -o $@ ${INCLUDE} ${LIBFT_INCUDE}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}

clean:
	${RM} -r ${OBJS_PATH}
	${MAKE} -C ${LIBFT_PATH} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re
