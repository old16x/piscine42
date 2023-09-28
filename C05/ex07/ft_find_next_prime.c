/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:43:00 by aradix            #+#    #+#             */
/*   Updated: 2023/09/21 16:10:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb < 2 || nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb < 3)
		nb = 3;
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
