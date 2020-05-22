/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:48:10 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/22 00:19:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static char	*get_line(char *hold)
{
	int		k;
	char	*line;

	k = 0;
	
	while (hold[k] && hold[k] != '\n')
		k++;
	line = ft_substr(hold, 0, k);
	hold = ft_substr(hold, k+1, ft_strlen(hold));
	// ft_putendl_fd(hold, 1);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char		*hold = NULL;
	char			data[BUFFER_SIZE + 1];
	int				rb;

	// (void)line;
	
	while (!(ft_strchr(data, '\n')) && (rb = read(fd, data, BUFFER_SIZE)))
	{
		data[rb] = '\0';

		hold = (hold) ? ft_strjoin(hold, data) : ft_strdup(data);
		printf("hold = %s\n", hold);
	}

	if (is_line(hold))
	{
		*line = get_line(hold);
		// printf("hold = %s\nline = %s\n", hold, *line);
		return (1);
	}
	return (0);
}