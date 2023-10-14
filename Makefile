# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/10/14 18:12:18 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##----Executable File Name-----##
NAME		= minishell
##-----------------------------##



##-----Directory Location------##
HEAD		= ./includes/

PRE			= ./srcs/

ERROR		= error/

INIT		= init/

SIGNAL		= signal/

BUILTIN		= built_in/

LEXER		= lexer/

PARSER		= parser/

REDIRECT	= redirect/

UNFOLD		= unfold/

PIPE		= pipe/

LIBFT		= libft/
##-----------------------------##



##------------Srcs-------------##
MAINSRC			= main.c standby_state.c \
					execution_main.c external_command.c malloc_free.c command_in_redirect.c

ERRORSRC		= malloc_error.c syntax.c file.c no_command.c

INITSRC			= init_minishell.c init_env.c init_exp.c

SIGNALSRC		= signal.c heredoc_signal.c

BULITINSRC		= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
				built_in_exit.c built_in_pwd.c built_in_unset.c built_in_export.c \
				built_in_helper.c built_in_export_helper.c

LEXERSRC		= lexer_main.c split_word.c

PARSERSRC		= parser_main.c split_pipe.c list_new.c list_add_back.c parser_contents.c parser_utils.c

REDIRECTSRC		= redirect_main.c append.c heredoc.c input.c output.c quote_heredoc.c redirect_utils.c

UNFOLDSRC		= unfold_main.c remove_quote.c unfold_quote_variable.c unfold_unquote_variable.c \
					unfold_helper.c

PIPESRC			= pipe_main.c init_pipe.c pipe_execve.c

SRCS		= ${MAINSRC} ${addprefix ${ERROR}, ${ERRORSRC}} ${addprefix ${BUILTIN}, ${BULITINSRC}} ${addprefix ${LEXER}, ${LEXERSRC}} \
				${addprefix ${PARSER}, ${PARSERSRC}} ${addprefix ${REDIRECT}, ${REDIRECTSRC}} \
				${addprefix ${UNFOLD}, ${UNFOLDSRC}} \
				${addprefix ${INIT}, ${INITSRC}} ${addprefix ${SIGNAL}, ${SIGNALSRC}} \
				${addprefix ${PIPE}, ${PIPESRC}}
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
			${CC} ${CFLAGS} -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include -c $< -o $@

${NAME}:	${OBJS}
			@${CCLIBFT}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -Lsrcs -lreadline -L /Users/csakamot/.brew/Cellar/readline/8.2.1/lib -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include ${ARCHIVES} -o ${NAME}
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