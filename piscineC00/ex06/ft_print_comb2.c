/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:01:43 by aradix            #+#    #+#             */
/*   Updated: 2023/09/07 09:15:07 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	tmp;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			tmp = (a / 10) + '0';
			write(1, &tmp, 1);
			tmp = (a % 10) + '0';
			write(1, &tmp, 1);
			write(1, " ", 1);
			tmp = (b / 10) + '0';
			write(1, &tmp, 1);
			tmp = (b % 10) + '0';
			write(1, &tmp, 1);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
