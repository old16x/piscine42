/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:39:06 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 17:08:09 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_dict(t_entry *head)
{
	t_entry	*current;

	current = head;
	while (current)
	{
		ft_putstr(current->key);
		ft_putstr(" : ");
		ft_putstr(current->value);
		ft_putstr("\n");
		current = current->next;
	}
}
