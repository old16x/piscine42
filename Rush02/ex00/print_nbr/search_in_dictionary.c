/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_dictionary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:01:57 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 22:49:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	expand_answer(char **answer, char *value)
{
	if (*answer)
	{
		*answer = ft_strexpand(*answer, " ");
		if (!*answer)
			return (3);
	}
	*answer = ft_strexpand(*answer, value);
	if (!*answer)
		return (3);
	return (0);
}

int	search_in_dictionary(char *nbr, t_entry **head, char **answer)
{
	t_entry	*current;

	current = *head;
	while (current)
	{
		if (ft_strcmp(current->key, nbr) == 0)
		{
			if (expand_answer(answer, current->value))
				return (3);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	find_unit(int n_zero, t_entry **head, char **answer)
{
	t_entry	*current;
	int		i;

	if (n_zero < 2)
		return (0);
	current = *head;
	while (current)
	{
		i = 0;
		if (current->key[i] == '1')
		{
			i++;
			while (current->key[i])
				if (current->key[i++] != '0')
					break ;
			if (current->key[i] == '\0' && i == n_zero)
			{
				if (expand_answer(answer, current->value))
					return (3);
				return (0);
			}
		}
		current = current->next;
	}
	return (1);
}
