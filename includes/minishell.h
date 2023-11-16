/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/16 11:57:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---include---*/
# include "../libft/libft_include/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <termcap.h>
/*-------------*/

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---Structure_Declaration---*/

// QUOTE_HEREDOC << '', << ""
// HEREDOC <<
// INPUT <
// APPEND >>  (追加)
// OUTPUT >
// UNKNOWN

extern volatile sig_atomic_t	g_signal;
typedef enum e_r_type
{
	Q_H,
	HEREDOC,
	INPUT,
	APPEND,
	OUTPUT,
	UNKNOWN
}			t_r_type;

typedef enum e_signal_type
{
	NORMAL,
	REDIRECT,
	INTERACTIVE,
	IGN
}						t_signal_type;

typedef struct s_env
{
	int					head;
	int					status;
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
	struct sigaction	act1;
	struct sigaction	act2;
}						t_signal;

typedef struct s_exe
{
	pid_t				pid;
	size_t				exe_flag;
}				t_exe;

typedef struct s_pipe
{
	pid_t			pid;
	size_t			head;
	int				pipe[2];
	char			*file;
	char			**array;
	struct s_pipe	*prev;
	struct s_pipe	*next;
}			t_pipe;

typedef struct s_file
{
	int					fd;
	char				*file_name;
	t_r_type			type;
	struct s_file		*next;
}			t_file;

typedef struct s_parser
{
	char				*all;
	char				*cmd;
	char				*option;
	t_file				*redirect;
	struct s_parser		*next;
	struct s_parser		*prev;
}			t_parser;

typedef struct s_data
{
	char				*prompt;
	t_exe				*exe;
	t_signal			*signal;
	t_parser			*parser;
	t_env				*env;
	t_exp				*exp;
}				t_data;
/*---------------------------*/

t_data	*init_minishell(t_data *data);
t_data	*init_env(t_data *data);
t_data	*init_exp(t_data *data);
t_env	*new_env_node(char *content, size_t head);
t_exp	*new_exp_node(char *content, size_t head);
void	execution_main(t_data *data);
int		dup_command(t_data *data, t_parser *parser, char *str, char **array);
int		without_fork_dup_command(t_data *data, t_parser *parser, \
												t_file *file, t_pipe *pipelist);
void	close_fd(t_file *file);
int		last_input_fd(t_file *file);
int		last_output_fd(t_file *file);
char	*format_command(t_parser *parser);
void	env_nodeadd_back(t_env **env, t_env *new);
void	exp_nodeadd_back(t_exp **env, t_exp *new);
void	standby_state(t_data *data);
void	exit_status_format(t_env *env, int status);

/*---external_command---*/
void	fork_and_execve(t_data *data, t_parser *parser, char **array);
size_t	optionlen(char *option);
size_t	arraylen(char **array);
void	add_option_to_array(char **result, char *option, size_t *index);
void	add_file_to_array(char **result, char **array, size_t index, \
																size_t len);
char	*check_cmd_path(t_env *env_variable, t_parser *parser);
char	*check_cmd_access(t_parser *parser, char **path);
char	*set_absolute_path(char *cmd);
int		check_absolute_path(char *cmd);
char	**create_command(t_parser *parser, char **array);
char	**struct_to_array(t_env *env);
/*---------------------*/

/*---signal---*/
void	signal_minishell(t_signal *sig, int flag);
void	signal_heredoc(t_signal *signal);
void	signal_interactive(t_signal *signal);
/*------------*/

/*---free---*/
void	double_array_free(char **array);
void	delete_all_env_node(t_env *env_variable);
void	delete_all_exp_node(t_exp *exp_variable);
void	parser_free(t_parser *node);
void	free_all(t_data *data);
/*----------*/
#endif
