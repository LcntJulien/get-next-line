/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/12 18:00:10 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*makeline(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] != '\n' || stash[i] != '\0')
		i++;
	line = ft_calloc(i, sizeof(char));
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	else
		line[i] = '\0';
	return (line);
}

int	findnextline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i++])
	{
		if (stash[i] == '\n')
			return (1);
	}
	return (0);
}

char	*cleanbuf(char *buf, int nextline)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nextline > 0)
	{
		while (buf[i] != '\n')
			i++;
		while (buf[++i] != '\0')
			buf[j++] = buf[i];
		while (buf[++j])
			buf[j] = '\0';
	}
	return (buf);
}

char	*process(int filedes)
{
	int		i;
	char	*stash;
	char	*line;
	char	*buffer;

	i = 0;
	stash = 0;
	line = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (i > 0)
	{
		i = read(filedes, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			break ;
		}
		buffer[i] = '\0';
		ft_strjoin(stash, buffer);
		if (findnextline(stash) > 0)
			break ;
	}
	line = makeline(stash);
	buffer = cleanbuf(buffer, findnextline(stash));
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	else
		line = process(fd);
	return (line);
}
