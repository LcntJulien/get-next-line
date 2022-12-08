/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:06:39 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/08 13:44:55 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*p;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	p = malloc(sizeof(char) * len);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	int		size;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s + start))
		size = len;
	else
		size = ft_strlen(s + start);
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (NULL);
	while (*(s + start) && i < len)
	{
		*(char *)(p + i) = *(char *)(s + start);
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	checkset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = ft_strlen(s1);
	if (s1 != 0)
	{
		while (*(s1 + i) && checkset(*(s1 + i), set))
			i++;
		if (i == j)
			return (p = ft_strdup(""));
		while (checkset(*(s1 + j - 1), set) && *(s1 + j - 1))
			j--;
		return (p = ft_substr(s1, i, (j - i)));
	}
	return (0);
}