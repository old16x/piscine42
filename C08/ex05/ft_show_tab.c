/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:54:58 by aradix            #+#    #+#             */
/*   Updated: 2023/09/27 17:29:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	n;
	char	tmp;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	tmp = (n % 10) + '0';
	write(1, &tmp, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (!par || !(*par).str)
		return ;
	while (par[i].str)
	{
		ft_putstr((par[i]).str);
		ft_putstr("\n");
		ft_putnbr((par[i]).size);
		ft_putstr("\n");
		ft_putstr((par[i]).copy);
		ft_putstr("\n");
		i++;
	}
}
