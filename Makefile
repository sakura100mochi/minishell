# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2023/09/21 06:18:55 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME		= minishell
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/

PRE			= ./srcs/

BUILTIN		= built_in/

LEXER		= lexer/

PARSER		= parser/

LIBFT		= ${addprefix ${PRE}, libft/}
##-----------------------------##



##------------Srcs-------------##
MAINSRC		= minishell.c init_minishell.c init_env.c standby_state.c \
				signal.c external_command.c malloc_free.c

BULITINSRC	= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
				built_in_exit.c built_in_pwd.c built_in_unset.c built_in_main.c \
				built_in_export.c built_in_helper.c

LEXERSRC	= lexer_main.c split_word.c single_quotation.c double_quotation.c

PARSERSRC	= parser_main.c split_pipe.c ft_parsernew.c ft_parseradd_back.c parser_contents.c ft_bzero_double.c make_add_node.c

SRCS		= ${MAINSRC} ${addprefix ${BUILTIN}, ${BULITINSRC}} ${addprefix ${LEXER}, ${LEXERSRC}}
# ${addprefix ${PARSER}, ${PARSERSRC}}
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRCS:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= make -s -C srcs/libft
##-----------------------------##



##------------remove-----------##
RMLIBFT		= make fclean -s -C srcs/libft
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -I/usr/include -c $< -o $@

${NAME}:	${OBJS}
			@${CCLIBFT}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -Lsrcs ${ARCHIVES} -lreadline -o ${NAME}
#			@echo "minishell		created\n\n"
#			@echo "    ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
#			@echo "    ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
#			@echo "    ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
#			@echo "    ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
#			@echo "    ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
#			@echo "    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
#			@echo "                                                                       "


# -fsanitize=address
clean:
			@${RM} ${OBJS}
			@${RMLIBFT}
			@echo "object file		removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "minishell		removed"

re:			fclean all

exe:		re
			@make -s clean

.PHONY:		all clean fclean re exe
##-----------------------------##