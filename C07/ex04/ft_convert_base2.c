/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:19 by aradix            #+#    #+#             */
/*   Updated: 2023/09/26 13:21:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_print(long n, char *base, char **ret, unsigned int *i)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_print(n / base_len, base, ret, i);
	(*ret)[*i] = base[n % base_len];
	(*i)++;
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
