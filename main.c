/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:45:36 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/16 17:55:21 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd = open("giant_line_nl.txt", O_RDONLY);
    printf("%s%s", get_next_line(fd), get_next_line(fd));
    close(fd);
}