/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2023/09/08 14:56:58 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freedent(char **s)
{
	free(*s);
	*s = 0;
	return (*s);
}

char	*cleanstash(char *stash)
{
	int		i;
	int		len;
	char	*newstash;

	i = 0;
	len = 0;
	if (!stash[i])
	{
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	newstash = malloc(sizeof(char) * (gnl_strlen(stash) - i));
	if (!newstash)
		return (stash = freedent(&stash));
	if (stash[i] == '\n')
		i++;
	while (stash[i])
	{
		newstash[len++] = stash[i++];
	}
	newstash[len] = 0;
	free(stash);
	return (newstash);
}

char	*makeline(char *stash, char	*line)
{
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		i--;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*getstash(int fd, char *stash)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (stash = freedent(&stash));
	while (!gnl_strchr(stash, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		stash = gnl_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (stash = freedent(&stash));
	line = 0;
	stash = getstash(fd, stash);
	if (!stash || !stash[0])
	{
		if (stash)
			free(stash);
		stash = 0;
		return (NULL);
	}
	line = makeline(stash, line);
	if (!line)
		return (stash = freedent(&stash));
	stash = cleanstash(stash);
	return (line);
}

int main(int ac, char **av)
{
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    char    *s = get_next_line(fd);
    fprintf(stderr, "%s", s);

    while (s)
    {
        fprintf(stderr, "%s", s);
        s = get_next_line(fd);
    }
}