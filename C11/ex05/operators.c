/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:05:50 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 12:31:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_putnbr(a / b);
}

void	ft_mult(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(a % b);
}
