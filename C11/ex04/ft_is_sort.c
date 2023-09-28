/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:26:42 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 09:38:59 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	i = 0;
	ascending = 0;
	descending = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			descending++;
		if (f(tab[i], tab[i + 1]) <= 0)
			ascending++;
		i++;
	}
	if (i == ascending || i == descending)
		return (1);
	return (0);
}
