/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:09:57 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:14:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_isprint(int c)
{
	int	flag;

	flag = 0;
	if (32 <= c && c <= 126)
		flag = 1;
	return (flag);
}
