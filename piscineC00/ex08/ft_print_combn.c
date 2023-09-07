/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:03:24 by aradix            #+#    #+#             */
/*   Updated: 2023/09/07 14:39:41 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int		i;
	char	comb[10];

	if (n <= 0 || n >= 10)
		return ;
	i = -1;
	while (i++ < n - 1)
		comb[i] = i + '0';
	while (1)
	{
		i = n - 1;
		while (comb[i] <= (10 - ((n - i)) + '0'))
		{
			write(1, &comb, n);
			if (comb[0] == 10 - n + '0')
				return ;
			write(1, ", ", 2);
			comb[i]++;
		}
		while (i > 0 && comb[i] >= (10 - ((n - i)) + '0'))
			i--;
		comb[i]++;
		while (i++ < n - 1)
			comb[i] = comb[i - 1] + 1;
	}
}
