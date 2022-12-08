/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/08 13:40:48 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	process(int len, char *line, int fd)
{
	int			i;
	int			j;
	static char	*stash;
	void		*buf[BUFFER_SIZE + 1];

	i = 0;
	j = BUFFER_SIZE;
	stash = 0;
	while (j != 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		ft_strjoin(stash, buf);
		while (stash[i++])
		{
			if (stash[i] == "$")
			{
				line += ft_strtrim(ft_substr(stash, 0, i), "$");
				ft_putstr(line);
				len += ft_strlen(line);
				break ;
			}
		}
	}
	return (len);
}

char	*get_next_line(int fd)
{
	int		linelen;
	char	*line;

	linelen = 0;
	line = 0;
	if (!fd)
		return (NULL);
	else
		linelen += process(linelen, line, fd);
	return (linelen);
}
