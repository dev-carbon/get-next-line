/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:07:01 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/22 22:16:18 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY | O_CREAT);
//	printf("%d\n", get_next_line(fd, &line));
		while ((get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
	return (0);
}
