/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/12 12:37:19 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*makeline(char *stash)
{
	size_t	i;
	int		j;
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

char	*cleanbuf(char	*buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	while (buf[++i] != '\0')
		buf[j++] = buf[i];
	while (buf[++j])
		buf[j] = '\0';
	return (buf);
}

char	*process(char *buffer, int filedes)
{
	int		i;
	char	*stash;
	char	*line;

	i = 0;
	stash = 0;
	line = 0;
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
	buffer = cleanbuf(buffer);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = 0;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	else
		line = process(buf, fd);
	return (line);
}
