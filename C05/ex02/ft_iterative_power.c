/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:35:29 by aradix            #+#    #+#             */
/*   Updated: 2023/09/20 17:52:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	while (power-- > 1)
		nb *= nb;
	return (nb);
}
