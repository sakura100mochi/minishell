# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/09/24 19:52:09 by yhirai           ###   ########.fr        #
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

ERROR_P		= parser/Error_parser/

REDIRECT	= redirect/

ERROR_R		= redirect/Error_redirect/

LIBFT		= ${addprefix ${PRE}, libft/}
##-----------------------------##



##------------Srcs-------------##
MAINSRC		= minishell.c init_minishell.c init_env.c init_exp.c \
				standby_state.c signal.c execution_main.c external_command.c \
				malloc_free.c

BULITINSRC	= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
				built_in_exit.c built_in_pwd.c built_in_unset.c built_in_main.c \
				built_in_export.c built_in_helper.c

LEXERSRC	= lexer_main.c split_word.c single_quotation.c double_quotation.c

PARSERSRC	= parser_main.c split_pipe.c list_new.c list_add_back.c parser_contents.c parser_utils.c

ERROR_P_SRC	= malloc_error.c
REDIRECTSRC	= redirect_main.c append.c heredoc.c input.c output.c quote_heredoc.c

ERROR_R_SRC	= syntax.c

SRCS		= ${MAINSRC} ${addprefix ${BUILTIN}, ${BULITINSRC}} ${addprefix ${LEXER}, ${LEXERSRC}} ${addprefix ${PARSER}, ${PARSERSRC}} ${addprefix ${ERROR_P}, ${ERROR_P_SRC}} ${addprefix ${REDIRECT}, ${REDIRECTSRC}} ${addprefix ${ERROR_R}, ${ERROR_R_SRC}}
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
			${CC} ${CFLAGS}  -c $< -o $@

${NAME}:	${OBJS}
			@${CCLIBFT}
			@echo "object file		compiled"
			@${CC} ${CFLAGS} ${OBJS} -Lsrcs -lreadline ${ARCHIVES} -o ${NAME}
#			@echo "minishell		created\n\n"
#			@echo "    ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
#			@echo "    ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
#			@echo "    ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
#			@echo "    ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
#			@echo "    ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
#			@echo "    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
#			@echo "                                                                       "

# -L /Users/csakamot/.brew/Cellar/readline/8.2.1/lib -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include
# -I /Users/csakamot/.brew/Cellar/readline/8.2.1/include

# -I/usr/local/opt/readline/include
# -L/usr/local/Cellar/readline/8.2.1/lib/
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