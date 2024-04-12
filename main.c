/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:52:09 by astefans          #+#    #+#             */
/*   Updated: 2024/04/08 16:01:30 by astefans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	FILE *file = fopean("file.txt", "r");
	if (file == NULL)
	{
		perror("Nie mozna otworzyć pliku");
		return (1);
	}


	char *line;
	int read_res;
	while ((read_result = get_next_line(fileno(file), &line)) > 0)
	{
		printf("Odczytano linie: %s\n", line);
		free(line);
	}
	if (read_result < 0)
	{
		perror("Blad odczytu");
		return (1);
	}
	fclose(file);
	return (0);
}


