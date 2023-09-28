/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:10:22 by aradix            #+#    #+#             */
/*   Updated: 2023/09/21 10:37:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			left;
	int			right;
	long long	mid;
	long long	tmp;

	if (nb <= 0)
		return (0);
	left = 0;
	right = nb / 2 + 1;
	while (left <= right)
	{
		mid = (long long)(left + right) / 2;
		tmp = mid * mid;
		if (tmp == nb)
			return (mid);
		if (tmp < nb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}
