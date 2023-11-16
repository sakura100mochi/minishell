/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/11/17 08:21:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---pipe---*/
int		pipe_main(t_data *data, t_parser *parser, size_t len);
t_pipe	*init_pipe(t_data *data, size_t len);
void	execve_without_fork(t_data *data, t_parser *parser, t_pipe *pipelist);
void	do_pipe_dup_exec(t_data *data, t_parser *parser, t_pipe *pipelist);
void	parent_process_pipe(t_parser *parser, t_pipe *pipelist, size_t *index);
void	pipe_end_process(t_data *data, t_pipe *pipelist);
void	pipe_print_error(int status, char *cmd);
void	pipe_free(t_pipe *pipelist);
/*----------*/

#endif