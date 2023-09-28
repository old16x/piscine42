/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon < neleon@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:37:17 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 16:50:43 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	solver(t_struct s_map_struct, int y, int x, int value)
{
	if (y == s_map_struct.map_size)
	{
		if (check_map_validity(s_map_struct.map, s_map_struct.map_descriptor,
				s_map_struct.map_size))
			ft_exit_success(s_map_struct);
	}
	if (x == s_map_struct.map_size)
	{
		solver(s_map_struct, y + 1, 0, 1);
		return ;
	}
	if (value >= 1 && value <= s_map_struct.map_size)
	{
		if (!is_value_in_column(s_map_struct.map, y, x, value + '0')
			&& !is_value_in_row(s_map_struct.map, y, x, value + '0'))
		{
			s_map_struct.map[y][x] = value + '0';
			solver(s_map_struct, y, x + 1, 1);
			s_map_struct.map[y][x] = '0';
		}
		if (value <= s_map_struct.map_size)
			solver(s_map_struct, y, x, value + 1);
	}
}
