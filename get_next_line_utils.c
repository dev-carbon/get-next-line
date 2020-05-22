/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:08:57 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/19 17:16:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	if (!(dup = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (*(s + (++i)))
		*(dup + i) = *(s + i);
	*(dup + i) = 0;
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[len1 + i] = s2[i];
	join[len1 + i] = '\0';
	return (join);
}
