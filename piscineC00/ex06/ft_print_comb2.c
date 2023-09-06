/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:01:43 by aradix            #+#    #+#             */
/*   Updated: 2023/09/06 19:57:28 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_writenbr(int n) {
	char c;
	c = (n/10) + '0';
	write(1, &c, 1);
	c = (n%10) + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		n1;
	int		n2;

	n1 = 0;
	n2 = 1;

	while (n1 < 99)
	{
		ft_writenbr(n1);
		write(1, " ", 1);
		ft_writenbr(n2);
		write(1, ", ", 2);
		n2++;
		if (n2 > 99)
		{
			n1++;
			n2 = n1;
			n2++;
		}
	}
}

int		main(void)
{
	ft_print_comb2();
	return 0;
}





