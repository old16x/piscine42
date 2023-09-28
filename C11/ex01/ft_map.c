/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:05 by aradix            #+#    #+#             */
/*   Updated: 2023/09/27 19:02:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new;

	i = 0;
	if (length <= 0)
		return (0);
	new = (int *)malloc(sizeof(int) * length);
	if (!new)
		return (0);
	while (i < length)
	{
		new[i] = f(tab[i]);
		i++;
	}
	return (new);
}
