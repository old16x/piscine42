/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:19:48 by npirard           #+#    #+#             */
/*   Updated: 2023/09/24 17:10:01 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

//Traverse buffer and parse any line contained within.
int	parse_buffer(t_entry **dict_head, char **line, int byte_r, char *buffer)
{
	int	i;

	*line = ft_strexpand(*line, buffer);
	i = 0;
	while (i < byte_r)
	{
		if (buffer[i] == '\n' || buffer[i] == EOF)
		{
			(*line)[ft_strlen(*line) - (BUFFER_SIZE - i)] = '\0';
			if (parse_line(dict_head, *line))
			{
				free(*line);
				return (2);
			}
			free(*line);
			*line = ft_strexpand(0, buffer + i + 1);
		}
		i++;
	}
	return (0);
}

int	parse_file(t_entry **dict_head, int file)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		byte_r;

	line = NULL;
	byte_r = read(file, buffer, BUFFER_SIZE);
	while (byte_r)
	{
		buffer[BUFFER_SIZE] = '\0';
		if (parse_buffer(dict_head, &line, byte_r, buffer))
			return (2);
		byte_r = read(file, buffer, BUFFER_SIZE);
	}
	if (line)
		free(line);
	return (0);
}
