/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:20:12 by aradix            #+#    #+#             */
/*   Updated: 2023/09/19 15:06:44 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(char **argv, int i, int j)
{
	char	*tmp;

	tmp = argv[i];
	argv[i] = argv[j];
	argv[j] = tmp;
}

void	ft_print_arg(char **argv)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 1;
	if (argc == 0)
		return (0);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			tmp = ft_strcmp(argv[j], argv[i]);
			if (tmp < 0)
				ft_swap(argv, i, j);
			j++;
		}
		i++;
	}
	ft_print_arg(argv);
	return (0);
}
