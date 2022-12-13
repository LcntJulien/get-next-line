/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:06:39 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/13 16:28:55 by jlecorne         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	*p;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	tmp = s1;
	p = malloc(sizeof(char) * len);
	if (!p)
		return (0);
	free(s1);
	while (tmp[i++])
		p[i] = tmp[i];
	while (s2[j++])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
