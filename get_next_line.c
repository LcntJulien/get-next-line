/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/08 17:48:13 by jlecorne         ###   ########.fr       */
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

//	boucle de read sur fd qui add buf a un stash(statique) a chaques iterations
//		if qui stop le processus apres avoir call sur une fct pour stash si on trouve nextline
// fct(aim 1) : sortir la line sans $ et ajouter un retour a la ligne (malloc)
// fct(aim 2) : nettoyer le stash

int	process(char *buffer, int filedes)
{
	int	i;

	i = 0;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	line = 0;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	else
		process(buf, fd);
	return (line);
}

// int			i;
// int			j;
// static char	*stash;
// void		*buf[BUFFER_SIZE + 1];

// i = 0;
// j = BUFFER_SIZE;
// stash = 0;
// while (i != 0)
// {
// 	i = read(fd, buf, BUFFER_SIZE);
// 	ft_strjoin(stash, buf);
// 	while (stash[j++])
// 	{
// 		if (stash[j] == "$")
// 		{
// 			line = treatline(stash);
// 			stash = treatstash(stash);
// 			break ;
// 		}
// 	}
// }
// return (line);