/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:47:09 by aradix            #+#    #+#             */
/*   Updated: 2023/09/10 20:49:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_int_to_hex(int n, char *convert_table)
{
	if (n > 16)
		ft_int_to_hex(n / 16, "0123456789abcdef");
	write(1, &convert_table[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
		{
			write(1, "\\0", 2);
			ft_int_to_hex(*str, "0123456789abcdef");
		}
		else
			write(1, str, 1);
		str++;
	}
}
