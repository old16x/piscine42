/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:34:36 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 12:43:05 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	ft_sort_string_tab(char **tab)
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
			tmp = ft_strcmp(tab[j], tab[i]);
			if (tmp < 0)
				ft_swap(tab, i, j);
			j++;
		}
		i++;
	}
}
