/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:48:10 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/22 22:10:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_line(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static char	*get_line(char **hold)
{
	int		k;
	char	*line;
	char	*tmp;

	k = 0;
	tmp = *hold;
	while (tmp[k] && tmp[k] != '\n')
		k++;
	line = ft_substr(tmp, 0, k);
	*hold = ft_substr(tmp, k + 1, ft_strlen(tmp));
	if (!line)
		return (NULL);
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char		*hold = NULL;
	char			data[BUFFER_SIZE + 1];
	int				rb;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rb = 0;
	while (!(ft_strchr(hold, '\n')) && (rb = read(fd, data, BUFFER_SIZE)) > 0)
	{
		data[rb] = '\0';
		hold = (hold) ? ft_strjoin(hold, data) : ft_strdup(data);
	}
	if (rb == -1)
		return (-1);
	if (is_line(hold))
	{
		if ((*line = get_line(&hold)))
			return (1);
		return (-1);
	}
	return (0);
}
