/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:58:59 by aradix            #+#    #+#             */
/*   Updated: 2023/09/26 13:22:24 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_get_index(char c, char *base, unsigned int b);
long	ft_power(unsigned int x, unsigned int n);
void	ft_print(long n, char *base, char **ret, unsigned int *i);

char	*ft_putnbr_base(long n, char *base)
{
	char			*ret;
	unsigned int	i;

	ret = (char *)malloc(sizeof(char) * (32 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
		i++;
	}
	ft_print(n, base, &ret, &i);
	ret[i] = '\0';
	return (ret);
}

long	ft_atoi_convert_base(char *str, char *base, unsigned int base_len)
{
	long	nb;
	int		value;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] && ft_get_index(str[i], base, base_len) >= 0)
		i++;
	while (*str && i--)
	{
		value = ft_get_index(*str, base, base_len);
		if (value < 0)
			return (nb);
		nb += value * ft_power(base_len, i);
		str++;
	}
	return (nb);
}

long	ft_atoi_base(char *str, char *base, int base_len)
{
	long			nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nb = ft_atoi_convert_base(str, base, base_len);
	if (nb > 0)
		return (nb * sign);
	return (0);
}

int	ft_check_base(char *base)
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
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_len;
	long	nbr_in_base_ten;

	base_len = ft_check_base(base_from);
	if (base_len < 2)
		return (NULL);
	nbr_in_base_ten = ft_atoi_base(nbr, base_from, base_len);
	base_len = ft_check_base(base_to);
	if (base_len < 2)
		return (NULL);
	return (ft_putnbr_base(nbr_in_base_ten, base_to));
}
