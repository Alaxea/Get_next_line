/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:33:45 by astefans          #+#    #+#             */
/*   Updated: 2024/04/18 10:13:54 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_after_start(char *start)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i = i + (start[i] == '\n');
	new_buffer = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buffer[j] = start[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(start);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			fd_read;
	static char	*start_str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	buff = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, buff, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[fd_read] = '\0';
		start_str = ft_strjoin(start_str, buff);
	}
	free(buff);
	buff = ft_read_line(start_str);
	start_str = ft_after_start(start_str);
	return (buff);
}

/*int main (void)
{
	FILE *file = fopen("file.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	char *line = NULL;
	while ((line = get_next_line(fileno(file))) != NULL)
	{
		printf("I readed this lines: %s\n", line);
		free(line);
	}
	fclose(file);
	return (0);
}*/
