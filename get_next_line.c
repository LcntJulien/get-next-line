/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/16 13:13:08 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanstash(char *stash, char *line)
{
	int		i;
	int		len;
	char	*newstash;

	i = 0;
	len = (ft_strlen(stash) - ft_strlen(line) + 1);
	newstash = ft_calloc(len, sizeof(char));
	while (stash[(ft_strlen(line) + i)] != '\0')
	{
		newstash[i] = stash[(ft_strlen(line) + i)];
		i++;
	}
	newstash[(ft_strlen(line) + i)] = '\0';
	return (newstash);
}

char	*catstash(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*getstash(int fd, char *stash)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		stash = catstash(stash, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*makeline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (ft_strrchr(stash, '\n'))
		line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = getstash(fd, stash);
	if (!stash)
		return (NULL);
	line = makeline(stash);
	stash = cleanstash(stash, line);
	return (line);
}
