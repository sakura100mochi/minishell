# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 02:35:02 by yayoi             #+#    #+#              #
#    Updated: 2023/09/17 18:51:14 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= libft.a

FTPRINTF		= ft_printf/

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

OBJS			= ${SRC:.c=.o}

FTPRINTF_OBJS	= ${FTPRINTF_SRC:.c=.o}

CFLAGS			= -Wall -Wextra -Werror

ARFLAG			= rcs

all:			$(NAME)

%.o:%.c
				@${CC} ${CFLAGS} -I libft_include -c $< -o $@

$(NAME):		${OBJS}
				@echo "libft			compiled"
				@${CC} ${CFLAGS} -I libft_include -c ${addprefix ${FTPRINTF}, ${FTPRINTF_SRC}}
				@${AR} ${ARFLAG} ${NAME} ${OBJS} ${FTPRINTF_OBJS}
				@echo "libft.a			created"

clean:
				@${RM} ${OBJS} ${FTPRINTF_OBJS}
				@echo "libft_object file	removed"

fclean:			clean
				@${RM} ${NAME}
				@echo "libft.a			removed"

re:				fclean all

.PHONY:			all bonus clean fclean re