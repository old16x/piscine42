/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:40:04 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 16:41:37 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	check_top_view(char **map, int map_size, int x)
{
	int		i;
	int		visible;
	char	max_height;

	i = 1;
	visible = 1;
	max_height = map[0][x];
	while (i < map_size)
	{
		if (map[i][x] > max_height)
		{
			max_height = map[i][x];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	check_bottom_view(char **map, int map_size, int x)
{
	int		i;
	int		visible;
	char	max_height;

	map_size--;
	i = map_size - 1;
	visible = 1;
	max_height = map[map_size][x];
	while (i >= 0)
	{
		if (map[i][x] > max_height)
		{
			max_height = map[i][x];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	check_left_view(char **map, int map_size, int y)
{
	int		i;
	int		visible;
	char	max_height;

	i = 1;
	visible = 1;
	max_height = map[y][0];
	while (i < map_size)
	{
		if (map[y][i] > max_height)
		{
			max_height = map[y][i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	check_right_view(char **map, int map_size, int y)
{
	int		i;
	int		visible;
	char	max_height;

	map_size--;
	i = map_size - 1;
	visible = 1;
	max_height = map[y][map_size];
	while (i >= 0)
	{
		if (map[y][i] > max_height)
		{
			max_height = map[y][i];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	check_map_validity(char **map, char **map_descriptor, int map_size)
{
	int	x;

	x = 0;
	while (x < map_size)
	{
		if ((map_descriptor[0][x] - '0') != check_top_view(map, map_size, x))
			return (0);
		if ((map_descriptor[1][x] - '0') != check_bottom_view(map, map_size, x))
			return (0);
		if ((map_descriptor[2][x] - '0') != check_left_view(map, map_size, x))
			return (0);
		if ((map_descriptor[3][x] - '0') != check_right_view(map, map_size, x))
			return (0);
		x++;
	}
	return (1);
}
