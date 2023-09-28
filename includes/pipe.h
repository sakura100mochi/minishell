/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/29 00:04:45 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---pipe---*/
int		pipe_main(t_init *state, t_parser *parser, t_pipe *pipe, size_t len);
t_pipe	*init_pipe(t_init *state, size_t len);
/*----------*/

#endif