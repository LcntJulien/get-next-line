/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:10 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/07 16:31:18 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int  fd)
{
    int r;
    void    *buf[BUFFER_SIZE + 1];
    static  char    *stash[1000];

}