/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:35:04 by sakamoto          #+#    #+#             */
/*   Updated: 2023/08/09 12:11:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

static int	ft_space(const char *nptr, int i)
{
	int	flag;

	flag = 0;
	while (('9' < nptr[i] || nptr[i] < '0') && nptr[i] != '\0')
	{
		flag = 0;
		if (9 <= nptr[i] && nptr[i] <= 13)
			flag++;
		if (nptr[i] == ' ' || nptr[i] == '	')
			flag++;
		if (flag != 0)
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_pulmi(const char *nptr, int i)
{
	int	flag;

	flag = 0;
	if (nptr[i] == '+')
		flag = 1;
	else if (nptr[i] == '-')
		flag = 2;
	return (flag);
}

static int	ftch(const char *nptr, unsigned long long result, int count, int i)
{
	int	flag;

	flag = 0;
	if (result >= LONG_MAX && count != 2)
		flag = 1;
	else if (result == SIZE_MAX / 10 && nptr[i + 1] > '5')
		flag = 1;
	else if (result > LONG_MAX && count == 2)
		flag = 2;
	return (flag);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			count;
	long long	result;

	i = 0;
	result = 0;
	i = ft_space(nptr, i);
	count = ft_pulmi(nptr, i);
	if (ft_pulmi(nptr, i))
		i++;
	while (nptr[i] != '\0')
	{
		if (48 <= nptr[i] && nptr[i] <= 57)
			result = result * 10 + (nptr[i] - '0');
		else
			break ;
		if (ftch(nptr, result, count, i) == 1)
			return (-1);
		else if (ftch(nptr, result, count, i) == 2)
			return (0);
		i++;
	}
	if (count == 2)
		result *= -1;
	return (result);
}
