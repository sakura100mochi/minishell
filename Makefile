# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/10/28 19:38:48 by hiraiyuina       ###   ########.fr        #
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
MAINSRC			= main.c standby_state.c check_cmd_path_utils.c exit_status.c\
					execution_main.c external_command.c malloc_free.c external_command_utils.c \
					command_in_redirect.c command_in_redirect_utils.c

ERRORSRC		= malloc_error.c syntax.c file.c no_command.c exit.c pipe_error.c

INITSRC			= init_minishell.c init_env.c init_exp.c

SIGNALSRC		= signal.c heredoc_signal.c intetactive_signal.c

BULITINSRC		= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
				built_in_exit.c built_in_pwd.c built_in_unset.c built_in_export.c \
				built_in_utils.c built_in_export_utils.c built_in_export_more_utils.c

LEXERSRC		= lexer_main.c split_word.c

PARSERSRC		= parser_main.c split_pipe.c list_new.c list_add_back.c parser_contents.c parser_utils.c

REDIRECTSRC		= redirect_main.c append.c heredoc.c input.c output.c quote_heredoc.c redirect_utils.c

UNFOLDSRC		= unfold_main.c remove_quote.c unfold_quote_variable.c unfold_unquote_variable.c \
					unfold_utils.c unfold_quote_variable_utils.c

PIPESRC			= pipe_main.c pipe_execve.c

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
CFLAGS		= -Wall -Wextra -Werror -I $(shell brew --prefix readline)/include

CCLIBFT		= make -s -C libft
##-----------------------------##



##------------remove-----------##
RMLIBFT		= make fclean -s -C libft
##-----------------------------##



##-----------archive-----------##
ARFLAG		= rcs

ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##

CHECK		= \033[36m[\033[0m✔\033[36m]\033[0m
REMOVE		= \033[38;5;211m[\033[0m✘\033[38;5;211m]\033[0m
GENERATE	= \033[38;5;227m[\033[0m➤\033[38;5;227m]\033[0m
BLUE		= \033[1;36m
YELLOW		= \033[38;5;227m
RED			= \033[38;5;211m
RESET		= \033[0m

##--------Makefile rule--------##
all:		${NAME}

%.o:%.c
	@ ${CC} ${CFLAGS} -c $< -o $@
	@  printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

${NAME}:	${OBJS}
	@ echo ""
	@ ${CCLIBFT}
	@ ${CC} ${CFLAGS} ${OBJS} -lreadline -L $(shell brew --prefix readline)/lib ${ARCHIVES} -o ${NAME}
	@ echo "$(CHECK) $(BLUE)finish Compiling minishell. $(RESET)"
	@ echo "                                                                       "
	@ echo "    ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@ echo "    ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@ echo "    ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@ echo "    ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@ echo "    ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@ echo "    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
	@ echo "                                                                       "
	


clean:
	@ ${RM} ${OBJS}
	@ ${RMLIBFT}
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files.$(RESET)\n"

fclean:
	@ ${RM} ${OBJS}
	@ ${RMLIBFT}
	@ ${RM} ${NAME}
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files and $(NAME).$(RESET)\n"

re:			fclean all

exe:		re
	@ make -s clean

.PHONY:		all clean fclean re exe
##-----------------------------##