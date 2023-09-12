/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:47:09 by aradix            #+#    #+#             */
/*   Updated: 2023/09/12 12:28:18 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(int n, char *hex_table)
{
	write(1, &hex_table[n], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write(1, "\\", 1);
			ft_puthex(str[i] / 16, "0123456789abcdef");
			ft_puthex(str[i] % 16, "0123456789abcdef");
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
