/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:05 by jlecorne          #+#    #+#             */
/*   Updated: 2023/02/27 17:31:51 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*freedent(char **s);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

size_t	gnl_strlen(char *str);

#endif
