/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:32:11 by astefans          #+#    #+#             */
/*   Updated: 2024/04/08 13:40:56 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!s1 || !s2 || !result)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[len] = 0;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != c && str[i] != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)s;
	while (n--)
		*tmp_ptr++ = 0;
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*tmp_ptr;

	if (num_elements >= 4294967295 || element_size >= 4294967295)
		return (NULL);
	tmp_ptr = malloc(num_elements * element_size);
	if (!tmp_ptr)
		return (NULL);
	ft_bzero(tmp_ptr, num_elements * element_size);
	return (tmp_ptr);
}
