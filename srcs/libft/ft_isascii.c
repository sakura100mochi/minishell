/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:53:50 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:13:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

int	ft_isascii(int c)
{
	int	flag;

	flag = 0;
	if (0 <= c && c <= 127)
		flag = 1;
	return (flag);
}
