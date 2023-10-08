# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/10/08 16:16:14 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##----Executable File Name-----##
NAME		= minishell
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/

PRE			= ./srcs/

INIT		= init/

SIGNAL		= signal/

BUILTIN		= built_in/

LEXER		= lexer/

PARSER		= parser/

ERROR_P		= parser/Error_parser/

REDIRECT	= redirect/

ERROR_R		= redirect/Error_redirect/

UNFOLD		= unfold/

PIPE		= pipe/

ERROR_PIPE	= pipe/Error_pipe/

LIBFT		= libft/
##-----------------------------##



##------------Srcs-------------##
MAINSRC			= main.c standby_state.c \
					execution_main.c external_command.c malloc_free.c

INITSRC			= init_minishell.c init_env.c init_exp.c

SIGNALSRC		= signal.c

BULITINSRC		= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
				built_in_exit.c built_in_pwd.c built_in_unset.c built_in_export.c \
				built_in_helper.c built_in_export_helper.c

LEXERSRC		= lexer_main.c split_word.c

PARSERSRC		= parser_main.c split_pipe.c list_new.c list_add_back.c parser_contents.c parser_utils.c

ERROR_P_SRC		= malloc_error.c

REDIRECTSRC		= redirect_main.c append.c heredoc.c input.c output.c quote_heredoc.c redirect_utils.c

ERROR_R_SRC		= syntax.c file.c

UNFOLDSRC		= unfold_main.c remove_quote.c unfold_quote_variable.c unfold_unquote_variable.c \
					unfold_helper.c

PIPESRC			= pipe_main.c init_pipe.c pipe_execve.c

ERROR_PIPE_SRC	= pipe_error_main.c

SRCS		= ${MAINSRC} ${addprefix ${BUILTIN}, ${BULITINSRC}} ${addprefix ${LEXER}, ${LEXERSRC}} \
				${addprefix ${PARSER}, ${PARSERSRC}} ${addprefix ${ERROR_P}, ${ERROR_P_SRC}} \
				${addprefix ${REDIRECT}, ${REDIRECTSRC}} ${addprefix ${ERROR_R}, ${ERROR_R_SRC}} \
				${addprefix ${UNFOLD}, ${UNFOLDSRC}} \
				${addprefix ${INIT}, ${INITSRC}} ${addprefix ${SIGNAL}, ${SIGNALSRC}} \
				${addprefix ${PIPE}, ${PIPESRC}} ${addprefix ${ERROR_PIPE}, ${ERROR_PIPE_SRC}}
##-----------------------------##



##-----------Object------------##
OBJS		= ${addprefix ${PRE}, ${SRCS:.c=.o}}
##-----------------------------##



##----------conpiler-----------##
CFLAGS		= -Wall -Wextra -Werror

CCLIBFT		= make -s -C libft
##-----------------------------##



##------------remove-----------##
RMLIBFT		= make fclean -s -C libft
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##



##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -c -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include $< -o $@

${NAME}:	${OBJS}
			@${CCLIBFT}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -Lsrcs -lreadline -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include -L /Users/csakamot/.brew/Cellar/readline/8.2.1/lib -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include ${ARCHIVES} -o ${NAME}
#			@echo "minishell		created\n\n"
#			@echo "    ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
#			@echo "    ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
#			@echo "    ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
#			@echo "    ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
#			@echo "    ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
#			@echo "    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
#			@echo "                                                                       "

#csakamoto_42
# -L /Users/csakamot/.brew/Cellar/readline/8.2.1/lib -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include
# -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include
#csakamoto_windows
# -I/usr/local/opt/readline/include
# -L/usr/local/Cellar/readline/8.2.1/lib/

#yhirai_42
# -L /Users/yhirai/.brew/Cellar/readline/8.2.1/lib -I /Users/yhirai/.brew/Cellar/readline/8.2.1/include
# -I /Users/yhirai/.brew/Cellar/readline/8.2.1/include
#yhirai_mac
# -L /opt/homebrew/Cellar/readline/8.2.1/lib -I /opt/homebrew/Cellar/readline/8.2.1/include
# -I /opt/homebrew/Cellar/readline/8.2.1/include

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