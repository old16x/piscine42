/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon < neleon@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:34:28 by aradix            #+#    #+#             */
/*   Updated: 2023/09/17 17:44:37 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (s[i])
	{
		write(1, &s[i], 1);
		if (i < len - 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_matrix(char **m)
{
	while (*m)
	{
		ft_putstr(*m);
		write(1, "\n", 1);
		m++;
	}
}

char	**ft_create_matrix(unsigned int size_x, unsigned int size_y)
{
	char			**m;
	unsigned int	i;

	m = (char **)malloc(sizeof(char *) * size_y + 1);
	if (!m)
		return (0);
	while (size_y--)
	{
		i = size_x;
		m[size_y] = (char *)malloc(sizeof(char) * size_x + 1);
		if (!m[size_y])
			return (0);
		m[size_y][size_x] = '\0';
		while (i--)
			m[size_y][i] = '0';
	}
	return (m);
}
