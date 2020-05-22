/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:07:01 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/22 00:21:57 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)ac;
	(void)av;
	fd = open("foo.txt", O_RDONLY | O_CREAT);

	// int i = 0;
	while ((get_next_line(fd, &line)))		
		ft_putendl_fd(line, 1);
		// printf("%d\n", ++i);
	return (0);
}
