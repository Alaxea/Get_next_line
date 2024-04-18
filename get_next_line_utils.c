/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:32:11 by astefans          #+#    #+#             */
/*   Updated: 2024/04/18 10:06:33 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_join_strings(char *dest, char *str1, char *str2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str1 && str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;

	if (!start)
	{
		start = (char *)malloc(1);
		start[0] = '\0';
	}
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_join_strings(ptr, start, buff);
	free(start);
	return (ptr);
}
