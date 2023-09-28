/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:05:55 by aradix            #+#    #+#             */
/*   Updated: 2023/09/19 15:08:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	if (argc < 0)
		return (0);
	while (argv[0][i])
		write(1, &argv[0][i++], 1);
	write(1, "\n", 1);
	return (0);
}
