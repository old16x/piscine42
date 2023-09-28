/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:28:44 by npirard           #+#    #+#             */
/*   Updated: 2023/09/24 14:28:46 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	*free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split_first(char *str, char sep)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	strs = (char **) malloc(3 * sizeof(char *));
	if (!strs)
		return (strs);
	strs[2] = NULL;
	while (str[i] && str[i] != sep)
		i++;
	strs[0] = ft_strndup(str, i);
	j = i + 1;
	while (str[i])
		i++;
	strs[1] = ft_strndup(str + j, i - j);
	if (!strs[0] || !strs[1])
		return (free_strs(strs));
	return (strs);
}

//Return number of string in strs. Last element of strs must be NULL.
//Return -1 if strs not provided.
int	get_strs_size(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (-1);
	while (strs && strs[i])
		i++;
	return (i);
}
