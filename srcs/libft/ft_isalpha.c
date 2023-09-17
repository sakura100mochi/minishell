/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:06 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:13:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_isalpha(int c)
{
	int	flag;

	flag = 0;
	if ('A' <= c && c <= 'Z')
		flag = 1;
	if ('a' <= c && c <= 'z')
		flag = 1;
	return (flag);
}
