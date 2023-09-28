/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:40:24 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 12:33:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	find_op(char sign)
{
	if (sign == '+')
		return (0);
	if (sign == '-')
		return (1);
	if (sign == '/')
		return (2);
	if (sign == '*')
		return (3);
	if (sign == '%')
		return (4);
	ft_putnbr(0);
	return (-1);
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		ret;
	void	(*op[5])(int x, int y);

	if (ac != 4)
		return (0);
	op[0] = &ft_add;
	op[1] = &ft_sub;
	op[2] = &ft_div;
	op[3] = &ft_mult;
	op[4] = &ft_mod;
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	ret = find_op(av[2][0]);
	if (ret >= 0)
		op[ret](a, b);
	ft_putstr("\n");
	return (0);
}
