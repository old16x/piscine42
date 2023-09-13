/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:05:23 by aradix            #+#    #+#             */
/*   Updated: 2023/09/13 14:08:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_print(long n, char *base, unsigned int base_len)
{
	unsigned char tmp;

	if (n >= base_len)
		ft_print(n / base_len, base, base_len);
	tmp = base[n % base_len];
	printf("%c\n", base_len);
	write(1, base[n % base_len], 1);

}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	long			n;

	n = nbr;
	if (!(base_len = ft_check_base(base)))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_print(n, base, base_len);
}

int	main(void)
{
	ft_putnbr_base(2, "0 ");
	return (0);
}
