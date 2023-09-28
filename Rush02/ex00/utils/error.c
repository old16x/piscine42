/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:37:53 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 21:18:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	free_line(char **strs, char *nbr, char *word, int ret)
{
	free_strs(strs);
	free(nbr);
	free(word);
	return (ret);
}

int	error(int error)
{
	if (error == 1)
		ft_putstr("Error\n");
	else if (error == 2)
		ft_putstr("Dict Error\n");
	else if (error == 3)
		ft_putstr("Allocation error\n");
	return (error);
}

int	free_all(t_entry **dict, char *path, char *nbr, int error)
{
	if (dict)
		free_dict(dict);
	if (path)
		free(path);
	if (nbr)
		free(nbr);
	return (error);
}
