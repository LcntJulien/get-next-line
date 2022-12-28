/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/28 16:41:33 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanstash(char *stash)
{
	int		i;
	int		len;
	char	*newstash;

	i = 0;
	len = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!newstash)
		return (NULL);
	i++;
	while (stash[i])
	{
		newstash[len++] = stash[i++];
	}
	newstash[i] = '\0';
	free(stash);
	return (newstash);
}

char	*makeline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
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
	if (!stash && fd == 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
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
	stash = cleanstash(stash);
	return (line);
}

// char	*catstash(char *stash, char *buffer)
// {
// 	char	*tmp;

// 	tmp = ft_strjoin(stash, buffer);
// 	free(stash);
// 	free(buffer);
// 	return (tmp);
// }

// char	*cleanstash(char *stash, char *line)
// {
// 	int		i;
// 	int		len;
// 	char	*newstash;

// 	i = 0;
// 	len = 0;
// 	if (!stash)
// 		return (NULL);
// 	if (!line)
// 		return (NULL);
// 	if (stash == line)
// 		return (NULL);
// 	while (stash[len] && stash[len] != '\n')
// 		len++;
// 	if (!stash[len])
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	newstash = ft_calloc((ft_strlen(stash) - len + 1), sizeof(char));
// 	if (!newstash)
// 		return (NULL);
// 	len++;
// 	while (stash[len])
// 		newstash[i++] = stash[len++];
// 	free(stash);
// 	return (newstash);
// }

// char	*makeline(char *stash)
// {
// 	int		i;
// 	int		len;
// 	char	*line;

// 	i = 0;
// 	len = 0;
// 	if (!stash)
// 		return (NULL);
// 	while (stash[len] && stash[len] != '\n')
// 		len++;
// 	line = ft_calloc((len + 2), sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 	{
// 		line[i] = stash[i];
// 		i++;
// 	}
// 	if (stash[i] && stash[i] == '\n')
// 		line[i++] = '\n';
// 	return (line);
// }

// char	*getstash(int fd, char *stash)
// {
// 	int		i;
// 	char	*buffer;

// 	i = 1;
// 	if (!stash)
// 		stash = ft_calloc(1, 1);
// 	if (!stash)
// 		return (NULL);
// 	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while (i > 0)
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[i] = '\0';
// 		stash = catstash(stash, buffer);
// 		if (ft_strrchr(stash, '\n'))
// 			break ;
// 	}
// 	return (stash);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*stash;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	stash = getstash(fd, stash);
// 	if (!stash || stash == 0)
// 		return (NULL);
// 	line = makeline(stash);
// 	if (!line)
// 		return (NULL);
// 	stash = cleanstash(stash, line);
// 	return (line);
// }

// char	*cleanstash(char *stash, char *line)
// {
// 	int		i;
// 	int		len;
// 	char	*newstash;

// 	if (!stash)
// 	{
// 		return (NULL);
// 	}
// 	if (!line)
// 		line = ft_calloc(1, sizeof(char));
// 	i = 0;
// 	len = (ft_strlen(stash) - ft_strlen(line) + 1);
// 	newstash = ft_calloc(len, sizeof(char));
// 	if (!newstash)
// 		return (NULL);
// 	while (stash[(ft_strlen(line) + i)] != '\0')
// 	{
// 		newstash[i] = stash[(ft_strlen(line) + i)];
// 		i++;
// 	}
// 	newstash[i] = '\0';
// 	free(stash);
// 	return (newstash);
// }

// char	*catstash(char *stash, char *buffer)
// {
// 	char	*tmp;

// 	tmp = ft_strjoin(stash, buffer);
// 	free(stash);
// 	return (tmp);
// }

// char	*getstash(int fd, char *stash)
// {
// 	int		i;
// 	char	*buffer;

// 	i = 1;
// 	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while (i > 0)
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		if (i == -1 || (!stash && i == 0))
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[i] = '\0';
// 		stash = catstash(stash, buffer);
// 		if (ft_strrchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	return (stash);
// }

// char	*makeline(char *stash)
// {
// 	int		i;
// 	char	*line;

// 	if (!stash)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	line = ft_calloc((i + 1), sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 	{
// 		line[i] = stash[i];
// 		i++;
// 	}
// 	if (ft_strrchr(stash, '\n'))
// 		line[i] = '\n';
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*stash;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 	{
// 		free(stash);
// 		stash = 0;
// 		return (NULL);
// 	}
// 	stash = getstash(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	line = makeline(stash);
// 	stash = cleanstash(stash, line);
// 	if (!line || line[0] == 0)
// 	{
// 		free(stash);
// 		free(line);
// 		stash = NULL;
// 		return (NULL);
// 	}
// 	return (line);
// }
