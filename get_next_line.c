/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/08 14:29:58 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	process(char *line, int fd)
{
	int			i;
	int			j;
	static char	*stash;
	void		*buf[BUFFER_SIZE + 1];

	i = 0;
	j = BUFFER_SIZE;
	stash = 0;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		ft_strjoin(stash, buf);
		while (stash[j++])
		{
			if (stash[j] == "$")
			{
				tmpline = ft_strtrim(ft_strlcpy(stash, ), "$");
				break ;
			}
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = 0;
	if (!fd)
		return (NULL);
	else
		line += process(line, fd);
	return (line);
}
