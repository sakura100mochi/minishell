# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 02:35:02 by yayoi             #+#    #+#              #
#    Updated: 2023/10/28 19:00:35 by hiraiyuina       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= libft.a

FTPRINTF		= ft_printf/

GNL				= get_next_line/

SRC				= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
					ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
					ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
					ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
					ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c \
					ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c\

FTPRINTF_SRC	= ft_printf.c ft_check_printf.c ft_process.c ft_putnbr_base_fd_cnt.c

GNL_SRC			= get_next_line.c get_next_line_utils.c

OBJS			= ${SRC:.c=.o}

FTPRINTF_OBJS	= ${FTPRINTF_SRC:.c=.o}

GNL_OBJS		= ${GNL_SRC:.c=.o}

CFLAGS			= -Wall -Wextra -Werror

ARFLAG			= rcs

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all:			$(NAME)

%.o:%.c
	@ ${CC} ${CFLAGS} -I libft_include -c $< -o $@
	@  printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(NAME):		${OBJS}
	@ echo ""
	@ ${CC} ${CFLAGS} -I libft_include -c ${addprefix ${FTPRINTF}, ${FTPRINTF_SRC}} ${addprefix ${GNL}, ${GNL_SRC}}
	@ ${AR} ${ARFLAG} ${NAME} ${OBJS} ${FTPRINTF_OBJS} ${GNL_OBJS}
	@ echo "$(CHECK) $(BLUE)finish Compiling libft. $(RESET)"

clean:
	@${RM} ${OBJS} ${FTPRINTF_OBJS} ${GNL_OBJS}

fclean:			clean
	@ ${RM} ${NAME}

re:				fclean all

.PHONY:			all bonus clean fclean re