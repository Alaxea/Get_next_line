/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:31:09 by astefans          #+#    #+#             */
/*   Updated: 2024/04/12 19:01:04 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}

char	*ft_delete(char *buffer)
{
	int		a;
	int		b;
	char	*line;

	a = 0;
	//find length_of_first_line
	while (buffer[a] && buffer[a] != '\n')
		a++;
	//if end_of_line = \0
	if (!buffer[a])
	{
		free(buffer);
		return (NULL);
	}
	//len_of_line - len_of_firstline + 1
	line = ft_calloc((ft_strlen(buffer) - a + 1), sizeof(char));
	a++;
	b = 0;
	//line is buffer
	while (buffer[a])
		line[b++] = buffer[a++];
	free(buffer);
	return (line);
}

//take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	//memory_for_line
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	//go to end_of_line
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	//if e_o_l is \0 or \n go to \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		byte_read;

	buffer = NULL;
	if (!result)
		result = ft_calloc(1, 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -42)
		{
			perror("Error reading file");
			free(buffer);
			free(result);
			return (NULL);
		}
		else if (byte_read == 0)
		{
			free(buffer);
			return (result);
		}
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_delete(buffer);
	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		free (buffer);	
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	return (line);
}

int main (void)
{
	FILE *file = fopen("file.txt", "r");
	if (file == NULL)
	{
		perror("I cannot open this file");
		return (1);
	}
	char *line = NULL;
	while ((line = get_next_line(fileno(file))) != NULL)
	{
		printf("I read this lines: %s\n", line);
		free(line);
	}
	fclose(file);
	return (0);
}
