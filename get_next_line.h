/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:05 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/08 13:41:41 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
# endif

#  include <fcntl.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>

	char *
	get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

# endif
