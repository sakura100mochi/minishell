/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:50:17 by yayoi             #+#    #+#             */
/*   Updated: 2023/08/09 12:14:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

static int	get_digit(long long nbr)
{
	unsigned int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static char	*insert_number(long long nbr, char *result, unsigned int digit)
{
	int	flag;

	flag = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		flag++;
	}
	result[digit] = '\0';
	while (digit > 0)
	{
		result[digit - 1] = nbr % 10 + '0';
		nbr /= 10;
		digit--;
	}
	if (flag)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	long long		nbr;
	char			*result;
	unsigned int	digit;

	nbr = (long long)n;
	digit = get_digit(nbr);
	if (n == 0)
		digit++;
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	result = insert_number(nbr, result, digit);
	return (result);
}
