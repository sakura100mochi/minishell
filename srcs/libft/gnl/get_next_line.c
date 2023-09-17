/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:14:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 15:17:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/get_next_line.h"

char	*ft_buf_check(int fd, char **buf)
{
	unsigned int	newl;
	char			*s1;
	char			*c;
	char			*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr_gnl(buf[fd], '\n');
	if (c)
	{
		s1 = buf[fd];
		newl = c - s1 + 1;
		buf[fd] = ft_substr_gnl(s1, newl, ft_strlen_gnl((const char *)buf[fd]));
		result = (ft_substr_gnl(s1, 0, newl));
		free(s1);
		return (result);
	}
	else
		return (NULL);
}

int	ft_read_check(char *res, int fd, char **buf, long long len)
{
	if (len == -1)
		return (0);
	else if (len == 0)
	{
		if (!ft_strlen_gnl(res))
			return (0);
		buf[fd] = NULL;
		return (1);
	}
	return (2);
}

char	*ft_input(char *result, int fd, char **buf, char *s1)
{
	long long	len;
	char		*c;

	len = 1;
	while (len)
	{
		len = read(fd, s1, BUFFER_SIZE);
		if (ft_read_check(result, fd, buf, len) == 1)
			return (result);
		else if (ft_read_check(result, fd, buf, len) == 0)
		{
			free(result);
			return (NULL);
		}
		s1[len] = '\0';
		c = ft_strchr_gnl(s1, '\n');
		if (c)
		{
			result = ft_strjoin_gnl(result, ft_substr_gnl(s1, 0, c - s1 + 1));
			buf[fd] = ft_substr_gnl(s1, c - s1 + 1, len - (c - s1 + 1));
			return (result);
		}
		result = ft_strjoin_gnl(result, ft_substr_gnl(s1, 0, len));
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*stock;
	char			*result;
	static char		*buf[FOPEN_MAX] = {NULL};

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_input(result, fd, buf, stock);
	free(stock);
	return ((char *)result);
}
