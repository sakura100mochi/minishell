/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/20 11:46:54 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---include---*/
# include "../srcs/libft/libft_include/libft.h"
# include "parser.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <termcap.h>
/*-------------*/

/*---path---*/
# define BINARY	"/bin/"
/*----------*/

/*---enum---*/
typedef enum e_error
{
	MALLOC_ERROR,
	NO_COMMAND
}				t_error;
/*----------*/

/*---Structure_Declaration---*/
typedef struct s_env
{
	int					head;
	char				*variable;
	struct s_env		*prev;
	struct s_env		*next;
}						t_env;

typedef struct s_signal
{
	struct sigaction	action;
}						t_signal;

typedef struct s_exe
{
	pid_t		pid;
	size_t		exe_flag;
	char		**command;
}				t_exe;

typedef struct s_init
{
	char		*prompt;
	t_exe		*exe;
	t_signal	*signal;
	t_parser	*parser;
	t_env		*env;
	t_error		*error;
}				t_init;
/*---------------------------*/

t_init	*init_minishell(t_init *state);
t_init	*init_env(t_init *state);
void	standby_state(t_init *state);
t_env	*new_node(char *content, size_t index);

/*---built_in---*/

/*--------------*/

/*---external_command---*/
void	external_command(t_init *state, t_exe *exe_built);
/*---------------------*/

/*---signal---*/
void	signal_minishell(struct sigaction action);
/*------------*/

/*---free---*/
void	double_array_free(char **array);
void	delete_all_env_node(t_env *env_variable);
/*----------*/
#endif