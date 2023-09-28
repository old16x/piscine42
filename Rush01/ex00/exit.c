/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:49:34 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 16:53:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

void	ft_free_memory(char **s, int size)
{
	while (size-- > 0)
		free(s[size]);
	free(s);
}

void	ft_exit_success(t_struct s_map_struct)
{
	ft_print_matrix(s_map_struct.map);
	ft_free_memory(s_map_struct.map, s_map_struct.map_size);
	ft_free_memory(s_map_struct.map_descriptor, s_map_struct.map_size);
	exit(EXIT_SUCCESS);
}

int	ft_exit_error(t_struct s_map_struct)
{
	ft_free_memory(s_map_struct.map, s_map_struct.map_size);
	ft_free_memory(s_map_struct.map_descriptor, s_map_struct.map_size);
	return (ft_error());
}
