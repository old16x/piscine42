/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:39:26 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 16:39:45 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	is_value_in_row(char **map, int y, int x, char value)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[y][i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	is_value_in_column(char **map, int y, int x, char value)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (map[i][x] == value)
			return (1);
		i++;
	}
	return (0);
}
