# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/11/11 15:59:20 by yhirai           ###   ########.fr        #
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
MAINSRC		= main.c standby_state.c check_cmd_path_utils.c exit_status.c\
				execution_main.c external_command.c malloc_free.c external_command_utils.c \
				command_in_redirect.c command_in_redirect_utils.c check_cmd_access.c \
				execution_main_utils.c
ERRORSRC	= malloc_error.c syntax.c file.c no_command.c exit.c pipe_error.c
INITSRC		= init_minishell.c init_env.c init_exp.c init_exp_utils.c
SIGNALSRC	= signal.c heredoc_signal.c intetactive_signal.c
BULITINSRC	= built_in.c built_in_cd.c built_in_echo.c built_in_env.c \
			built_in_exit.c built_in_pwd.c built_in_unset.c built_in_export.c \
			built_in_utils.c built_in_export_utils.c built_in_export_more_utils.c \
			built_in_split_file.c built_in_cd_utils.c built_in_do_export_utils.c \
			redeclare_export.c built_in_unset_utils.c
LEXERSRC	= lexer_main.c split_word.c
PARSERSRC	= parser_main.c split_pipe.c list_new.c list_add_back.c parser_contents.c parser_utils.c
REDIRECTSRC	= redirect_main.c append.c heredoc.c input.c output.c quote_heredoc.c redirect_utils.c
UNFOLDSRC	= unfold_main.c remove_quote.c unfold_quote_variable.c unfold_unquote_variable.c \
				unfold_utils.c unfold_quote_variable_utils.c
PIPESRC		= pipe_main.c pipe_main_utils.c pipe_execve.c init_pipe.c pipe_free.c

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

ifdef DEBUG
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif
##-----------------------------##

##------------libft------------##
RMLIBFT		= make fclean -s -C libft
CCLIBFT		= make -s -C libft
ARFLAG		= rcs
ARCHIVES	= ${addprefix ${LIBFT}, libft.a}
##-----------------------------##

##------------color-----------##
CHECK		= \033[36m[\033[0m✔\033[36m]\033[0m
REMOVE		= \033[38;5;211m[\033[0m✘\033[38;5;211m]\033[0m
GENERATE	= \033[38;5;227m[\033[0m➤\033[38;5;227m]\033[0m
BLUE		= \033[1;36m
YELLOW		= \033[38;5;227m
RED			= \033[38;5;211m
RESET		= \033[0m
##-----------------------------##

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

exe:
	@ make fclean
	@ make DEBUG=1
	@ make -s clean

debug:		fclean
	@ make DEBUG=1

.PHONY:		all clean fclean re exe
##-----------------------------##
