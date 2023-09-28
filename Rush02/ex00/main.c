/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:27:24 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 22:56:14 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	call_solver(char *nbr, t_entry **dict)
{
	char	*answer;
	int		ret;

	answer = NULL;
	ret = tranform_nbr(nbr, dict, &answer);
	if (ret || !answer)
	{
		free(answer);
		return (error(ret));
	}
	ft_putstr(answer);
	write(1, "\n", 1);
	free(answer);
	return (0);
}

int	main(int ac, char **av)
{
	char	*nbr;
	char	*path;
	t_entry	*dict;

	if (ac != 2 && ac != 3)
		return (error(1));
	if (parse_args(ac, av, &path, &nbr))
		return (error(1));
	dict = build_dict(path);
	if (!dict)
		return (free_all(NULL, path, nbr, 2));
	call_solver(nbr, &dict);
	free_all(&dict, path, nbr, 0);
	return (0);
}
