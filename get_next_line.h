/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:05 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/07 16:28:24 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H BUFFER_SIZE
#define GET_NEXT_LINE_H
#define BUFFER_SIZE = 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char    *get_next_line(int  fd);

#endif
