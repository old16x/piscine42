/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:23:56 by aradix            #+#    #+#             */
/*   Updated: 2023/09/27 15:53:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i-- > 0)
		dest[i] = src[i];
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*stock;
	int				i;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * ac + 1);
	if (!stock)
	{
		stock = NULL;
		return (stock);
	}
	i = 0;
	while (i < ac)
	{
		(stock[i]).size = ft_strlen(av[i]);
		(stock[i]).str = av[i];
		(stock[i]).copy = ft_strdup(av[i]);
		i++;
	}
	(stock[i]).str = 0;
	return (stock);
}
