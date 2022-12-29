/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:06:39 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/29 11:11:47 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = ft_strlen(s);
// 	while (i >= 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i--;
// 	}
// 	return (NULL);
// }

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

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*p;

// 	i = 0;
// 	j = 0;
// 	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
// 	p = malloc(sizeof(char) * len);
// 	if (!p)
// 		return (0);
// 	while (s1[i])
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		p[i + j] = s2[j];
// 		j++;
// 	}
// 	p[i + j] = '\0';
// 	return (p);
// }

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = ft_strlen(s);
// 	while (i >= 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i--;
// 	}
// 	return (0);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		*(char *)(s + i) = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*p;

// 	if (!count || !size)
// 		return (NULL);
// 	p = malloc(size * count);
// 	if (!p)
// 		return (NULL);
// 	ft_bzero(p, count * size);
// 	return (p);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*p;

// 	if (!s1)
// 		s1 = ft_calloc(1, sizeof(char));
// 	if (!s1)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	p = malloc(sizeof(char) * (len + 1));
// 	if (!p)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		p[i + j] = s2[j];
// 		j++;
// 	}
// 	p[i + j] = '\0';
// 	return (p);
// }
