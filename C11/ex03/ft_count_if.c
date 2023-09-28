/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:11:44 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 13:07:11 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!tab || !*tab)
		return (0);
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
