/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/18 18:49:18 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---include---*/
# include "../srcs/libft/libft_include/libft.h"
# include "built_in.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h> //linux
# include <termios.h>
# include <termcap.h>
/*-------------*/

/*---path---*/
# define BINARY	"/bin/"
/*----------*/

/*---maclo---*/
# define YES 1
# define NO 0
/*-----------*/

/*---enum---*/
typedef enum	e_error
{
	NO_COMMAND,
};
/*----------*/

/*---Structure_Declaration---*/
typedef struct s_signal
{
	struct sigaction	action;
}				t_signal;

typedef struct s_exe
{
	pid_t	pid;
	size_t	exe_flag;
	char	**command;
}				t_exe;

typedef struct s_parser
{
	char			*command;
	char			*option;
	char			*file_name;
	char			*redirection;
	char			*result;
	struct s_parser	*next;
	struct s_parser	*pre;
}			t_parser;

typedef struct s_init
{
	char		*prompt;
	t_exe		*exe;
	t_signal	*signal;
	t_parser	*parser;
	// t_env		*env;
}				t_init;
/*---------------------------*/

t_init	*init_minishell(t_init *state);
t_init	*init_env(t_init *state);
void	standby_state(t_init *state);
t_env	*new_node(char *content, size_t index);

/*---lexer---*/
char		**lexer_main(char *str);
char		*single_quotation(char **str);
char		*double_quotation(char **str);
char		*split_word(char **str);
/*-----------*/

/*---parser---*/
t_parser	*parser_main(char **str);
t_parser	*parsing(t_parser *parse, char **phrase);
int			check_command(char *str);
void		ft_bzero_double(char **str);
/*------------*/

/*---built_in---*/
int		judge_built_in(t_init *state, char **exe_buil_command);
void	built_in_cd(void);
void	built_in_echo(t_init *state);
void	built_in_env(t_init *state, t_env *env_variable);
void	built_in_exit(t_init *state);
void	built_in_pwd(void);
void	built_in_unset(void);
/*--------------*/

/*---external_command---*/
void		external_command(t_init *state, t_exe *exe_built);
/*---------------------*/

/*---signal---*/
void		signal_minishell(struct sigaction action);
/*------------*/

/*---free---*/
void		double_array_free(char **array);
/*----------*/
#endif