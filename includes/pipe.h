/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/30 17:41:22 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---pipe---*/
int		pipe_main(t_data *data, t_parser *parser, t_pipe *pipe, size_t len);
int		execve_without_fork(t_data *data, t_parser *parser, char *file);
t_data	*init_pipe(t_data *data, size_t len);
/*----------*/

#endif