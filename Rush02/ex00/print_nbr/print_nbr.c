/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:50:13 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 23:34:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	trim_nbr(char *nbr, int start, t_entry **head, char **answer)
{
	int		end;
	char 	tmp[3];

	end = start + 3;
	tmp[2] = '\0';
	while (start < end)
	{
		if (nbr[start] == '0')
		{
			start++;
			continue ;
		}
		if (start % 3 == 1)
		{
			if (nbr[start] == '1')
			{
				tmp[0] = nbr[start];
				tmp[1] = nbr[start + 1];
				search_in_dictionary(tmp, head, answer);
				return (0);
			}
			else {
				tmp[0] = nbr[start];
				tmp[1] = '0';
				search_in_dictionary(tmp, head, answer);
			}

		}
		else
		{
			tmp[0] = nbr[start];
			tmp[1] = '\0';
			search_in_dictionary(tmp, head, answer);
		}
		if (start % 3 == 0)
			search_in_dictionary("100", head, answer);
		start++;
	}
	return (0);
}

int	is_zero(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	tranform_nbr(char *nbr, t_entry **head, char **answer)
{
	int	i;
	int	size;
	int	ret;

	if (is_zero(nbr) == 0)
		return (search_in_dictionary("0", head, answer));
	i = 0;
	size = ft_strlen(nbr);
	while (i < size)
	{
		if (trim_nbr(nbr, i, head, answer))
			return (3);
		if ((nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0'))
		{
			ret = find_unit(size - i - 2, head, answer);
			if (ret)
				return (ret);
		}
		i += 3;
	}
	return (0);
}
