/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:55:54 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 18:12:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/*---include---*/
# include "minishell.h"
/*-------------*/

/*---pipe---*/
int		pipe_main(t_init *state, t_parser *parser, size_t len);
t_pipe	*init_pipe(size_t len);
/*----------*/

#endif