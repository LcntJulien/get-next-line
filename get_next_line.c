/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/13 17:35:28 by jlecorne         ###   ########.fr       */
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

char	*process(int filedes, char *buffer)
{
	int		i;
	char	*stash;
	char	*line;

	i = 1;
	line = 0;
	while (i > 0)
	{
		i = read(filedes, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (findnextline(stash))
			break ;
	}
	line = makeline(stash);
	buffer = cleanbuf(buffer, findnextline(stash));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	else
		line = process(fd, buffer);
	return (line);
}
