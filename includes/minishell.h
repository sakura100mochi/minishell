/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 12:11:31 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---include---*/
# include "../srcs/libft/libft_include/libft.h"
# include "parser.h"
# include "redirect.h"
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

typedef struct s_exp
{
	int					head;
	char				*variable;
	struct s_exp		*prev;
	struct s_exp		*next;
}						t_exp;

typedef struct s_signal
{
	struct sigaction	action;
}						t_signal;

typedef struct s_exe
{
	pid_t		pid;
	size_t		exe_flag;
}				t_exe;

typedef struct s_pipe
{
	int				pipe_fd[2];
	pid_t			pid;
	size_t			head;
	struct s_pipe	*prev;
	struct s_pipe	*next;
}			t_pipe;

typedef struct s_init
{
	char		*prompt;
	t_exe		*exe;
	t_pipe		*pipe;
	t_signal	*signal;
	t_parser	*parser;
	t_env		*env;
	t_exp		*exp;
	t_error		*error;
}				t_init;
/*---------------------------*/

t_init	*init_minishell(t_init *state);
t_init	*init_env(t_init *state);
t_init	*init_exp(t_init *state);
t_env	*new_env_node(char *content, size_t head);
t_exp	*new_exp_node(char *content, size_t head);
void	execution_main(t_init *state);
void	env_nodeadd_back(t_env **env, t_env *new);
void	exp_nodeadd_back(t_exp **env, t_exp *new);
void	standby_state(t_init *state);

/*---external_command---*/
void	fork_and_execve(t_init *state, t_exe *exe, \
							t_parser *parser, char *file);
/*---------------------*/

/*---signal---*/
void	signal_minishell(struct sigaction action);
/*------------*/

/*---free---*/
void	double_array_free(char **array);
void	delete_all_env_node(t_env *env_variable);
void	delete_all_exp_node(t_exp *exp_variable);
/*----------*/
#endif