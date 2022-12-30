/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:05:27 by jlecorne          #+#    #+#             */
/*   Updated: 2022/12/30 11:12:16 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
    printf("\n\n");
    get_next_line(fd);
    printf("\n\n");
    get_next_line(fd);
    printf("\n\n");
    get_next_line(fd);
    printf("\n\n");
    get_next_line(fd);
    close(fd);
}