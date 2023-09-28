/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:44:00 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 13:09:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	len;
	int	i;
	int	j;
	int	tmp;

	len = 0;
	i = 0;
	if (!tab || !*tab)
		return ;
	while (tab[len])
		len++;
	if (len < 2)
		return ;
	while (i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			tmp = cmp(tab[j], tab[i]);
			if (tmp < 0)
				ft_swap(tab, i, j);
			j++;
		}
		i++;
	}
}
