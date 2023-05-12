
NAME = libft.a

CC = cc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

AR = ar rc


## libft ##

SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_memchr.c
SRCS += ft_memchri.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memset.c
SRCS += ft_memmove.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strnjoin.c
SRCS += ft_strnjoinf1.c
SRCS += ft_strnjoinf2.c
SRCS += ft_strnjoinf.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_lstadd_back.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstclear.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstlast.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstsize.c


## ft_printf ##

SRCS += ft_printf.c
SRCS += ft_printc.c
SRCS += ft_printdi.c
SRCS += ft_printp.c
SRCS += ft_prints.c
SRCS += ft_printu.c
SRCS += ft_printx.c
SRCS += ft_printX.c


## get_next_line ##

SRCS += get_next_line.c


## paths ##

SRCS_PATH += srcs/
SRCS_PATH += srcs/libft/
SRCS_PATH += srcs/ft_printf/
SRCS_PATH += srcs/get_next_line/

vpath %.c ${SRCS_PATH}


## includes ##

INCLUDE += includes/


## headers ##
HEADERS += libft.h
HEADERS += ft_printf.h
HEADERS += get_next_line.h

vpath %.h ${INCLUDE}


## objs ##

OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}


## rules ##

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS}: ${OBJS_PATH}/%.o: %.c ${HEADERS} Makefile
	mkdir -p ${OBJS_PATH}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDE}

clean:
	${RM} -r ${OBJS_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
