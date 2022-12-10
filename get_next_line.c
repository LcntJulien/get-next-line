/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/10 13:17:27 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	findnextline(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(stash);
	while (stash[i++])
	{
		if (stash[i] == '\n')
			return (1);
	}
	return (NULL);
}

int	process(char *buffer, int filedes)
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
		{
			line = makeline(stash);
			buffer = cleanbuf(buffer);
			break ;
		}
	}
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

//	boucle de read sur fd qui add buf a un stash(statique) a chaques iterations
//		if qui stop le processus apres avoir call sur une fct pour stash si on trouve nextline
// fct(aim 1) : sortir la line sans $ et ajouter un retour a la ligne (malloc)
// fct(aim 2) : nettoyer le stash