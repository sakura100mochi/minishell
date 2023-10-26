/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/10/22 15:13:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---pipe---*/
int		pipe_main(t_data *data, t_parser *parser, size_t len);
int		execve_without_fork(t_data *data, t_parser *parser, \
									t_pipe *pipelist, char *file);
size_t	count_pipelist(t_pipe *pipelist);
/*----------*/

#endif