/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:56:28 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 05:50:18 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_create_matrix(unsigned int size_x, unsigned int size_y);

void	copy_args(char *map_descriptor, char *args, unsigned int line_len)
{
	unsigned int	i;

	i = 0;
	while (i * 2 < line_len)
	{
		map_descriptor[i] = args[i * 2];
		i++;
	}
}

char	**create_map_descriptor(char *args, unsigned int map_size)
{
	char			**map_descriptor;
	unsigned int	i;
	unsigned int	len_line;

	map_descriptor = ft_create_matrix(map_size, map_size);
	if (!map_descriptor)
		return (0);
	i = 0;
	len_line = map_size * 2;
	while (i < map_size)
	{
		copy_args(map_descriptor[i], &args[i * len_line], len_line);
		i++;
	}
	return (map_descriptor);
}

int	check_args(const char *raw_map)
{
	unsigned int	i;

	i = 0;
	if (!raw_map)
		return (0);
	while (raw_map[i])
	{
		if (i % 2 == 1 && raw_map[i] != ' ')
			return (0);
		if (i % 2 != 1 && (raw_map[i] < '1' || raw_map[i] > '4'))
			return (0);
		i++;
	}
	if (i == 31 || i == 49 || i == 71 || i == 98 || i == 127 || i == 161)
		return (4);
	return (0);
}
