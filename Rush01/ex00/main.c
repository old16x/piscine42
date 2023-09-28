/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:55:05 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 16:52:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	main(int argc, char **argv)
{
	t_struct	s_map_struct;

	s_map_struct.map_size = check_args(argv[1]);
	if (argc != 2 || !s_map_struct.map_size)
		return (ft_error());
	s_map_struct.map_descriptor = create_map_descriptor(argv[1],
			s_map_struct.map_size);
	if (!s_map_struct.map_descriptor)
	{
		ft_free_memory(s_map_struct.map_descriptor, s_map_struct.map_size);
		return (ft_error());
	}
	s_map_struct.map = ft_create_matrix(s_map_struct.map_size,
			s_map_struct.map_size);
	if (!s_map_struct.map_descriptor)
	{
		ft_free_memory(s_map_struct.map_descriptor, s_map_struct.map_size);
		ft_free_memory(s_map_struct.map, s_map_struct.map_size);
		return (ft_error());
	}
	solver(s_map_struct, 0, 0, 1);
	ft_exit_error(s_map_struct);
	return (0);
}
