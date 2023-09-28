/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:02 by aradix            #+#    #+#             */
/*   Updated: 2023/09/26 13:31:52 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	size;
	unsigned int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * (size));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
