/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:15:41 by yhirai            #+#    #+#             */
/*   Updated: 2023/10/01 16:03:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_include/get_next_line.h"

char	*ft_read(int fd, char **line)
{
	size_t	read_size;
	char	buf[BUFFER_SIZE + 1];
	char	*s;
	char	*tmp;
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	while (ft_strchr_g(buf) == 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		tmp = *line;
		*line = ft_strjoin_gnl(tmp, buf);
		free(tmp);
	}
	s = NULL;
	s = ft_sub_read(s, buf);
	return (s);
}

char	*ft_sub_read(char *s, char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0' || buf[i + 1] == '\0' )
		return (NULL);
	i++;
	s = ft_calloc_gnl(sizeof(char), ft_strlen(buf) - i + 1);
	if (s == NULL)
		return (NULL);
	while (buf[i] != '\0')
		s[j++] = buf[i++];
	return (s);
}

// 改行までを line に格納する
// 改行以降を save に保存する
char	*ft_save(char *save)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	tmp = save;
	while (save[i] != '\n')
		i++;
	i++;
	save = ft_calloc_gnl(sizeof(char), ft_strlen(tmp) - i + 1);
	if (save == NULL)
		return (NULL);
	if (tmp[i] == '\0')
	{
		free(tmp);
		free(save);
		return (NULL);
	}
	j = 0;
	while (tmp[i] != '\0')
		save[j++] = tmp[i++];
	free(tmp);
	return (save);
}

void	ft_join(char **line, char *save)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin_gnl(*line, save);
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (save != NULL)
	{
		ft_join(&line, save);
		if (ft_strchr_g(save) == 0)
			free(save);
		else
		{
			save = ft_save(save);
			if (line != NULL && ft_strlen(line) == 0)
				return (NULL);
			return (line);
		}
	}
	save = ft_read(fd, &line);
	if (line != NULL && ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;
// 	// char	str[10000000];

// 	i = 1;
// 	fd = open("test1.txt", O_RDONLY);
// 	// i = read(fd, str, 1000);
// 	// printf("%s, %d\n", str, i);
// 	while (i <= 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("%i:%s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }
