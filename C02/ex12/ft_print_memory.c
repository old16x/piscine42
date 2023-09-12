/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:51:04 by aradix            #+#    #+#             */
/*   Updated: 2023/09/12 13:09:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_addr_seciton(void *ptr)
{
	int			i;
	char		hex_str[17];
	intptr_t	address;
	int			digit;

	i = 15;
	address = (intptr_t)ptr;
	while (i >= 0)
	{
		digit = (address >> (i * 4)) & 0xF;
		if (digit < 10)
			hex_str[15 - i] = digit + '0';
		else
			hex_str[15 - i] = 'a' + digit - 10;
		i--;
	}
	hex_str[16] = '\0';
	write(1, hex_str, 16);
	write(1, ": ", 2);
}

void	ft_put_hex(int n, char *hex_table)
{
	write(1, &hex_table[n], 1);
}

void	ft_hex_section(char *s)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && s[i])
	{
		if (i > 0 && i % 2 == 0)
			write(1, " ", 1);
		ft_put_hex(s[i] / 16, "0123456789abcdef");
		ft_put_hex(s[i] % 16, "0123456789abcdef");
		i++;
	}
	while (i < 16)
	{
		if (i > 0 && i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
}

void	ft_char_section(char *s)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && s[i])
	{
		if (s[i] < ' ' || s[i] > '~')
			write(1, ".", 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	void			*tmp;

	if (size == 0 || !addr)
		return (NULL);
	tmp = addr;
	i = 0;
	while (i < size)
	{
		ft_addr_seciton(tmp);
		ft_hex_section(tmp);
		ft_char_section(tmp);
		write(1, "\n", 1);
		i += 16;
		tmp += 16;
	}
	return (addr);
}
