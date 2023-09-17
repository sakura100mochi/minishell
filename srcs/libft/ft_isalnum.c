/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:28:15 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:12:57 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	if ('0' <= c && c <= '9')
		flag = 1;
	if ('A' <= c && c <= 'Z')
		flag = 1;
	if ('a' <= c && c <= 'z')
		flag = 1;
	return (flag);
}
