/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:25 by aradix            #+#    #+#             */
/*   Updated: 2023/09/18 19:06:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i] || base[i] == '+' || base[i] == '-'
				|| base[i] == ' ' || base[i] == '\f' || base[i] == '\n'
				|| base[i] == '\r' || base[i] == '\t' || base[i] == '\v')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_get_index(char c, char *base, unsigned int b)
{
	while (b--)
		if (base[b] == c)
			return (b);
	return (-1);
}

long	ft_power(unsigned int x, unsigned int n)
{
	unsigned int	pow;
	unsigned int	i;

	pow = 1;
	i = 0;
	if (n == 0)
		return (1);
	while (i < n)
	{
		pow *= x;
		i++;
	}
	return (pow);
}

long	ft_convert_base(char *str, char *base, unsigned int b)
{
	long	nb;
	int		value;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] && ft_get_index(str[i], base, b) >= 0)
		i++;
	while (*str && i--)
	{
		value = ft_get_index(*str, base, b);
		if (value < 0)
			return (nb);
		nb += value * ft_power(b, i);
		str++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	long			nb;
	int				sign;
	unsigned int	b;

	nb = 0;
	sign = 1;
	b = ft_check_base(base);
	if (!b)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nb = ft_convert_base(str, base, b);
	if (nb > 0)
		return (nb * sign);
	return (0);
}
