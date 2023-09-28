/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:47:12 by aradix            #+#    #+#             */
/*   Updated: 2023/09/26 12:29:57 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_cpy(char *src, char	*dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		total_len;
	int		i;
	int		j;

	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	if (size > 0)
		total_len += ft_strlen(sep) * (size - 1);
	dest = (char *)malloc(sizeof(char) * (total_len + 1));
	dest[total_len] = '\0';
	if (!dest || size <= 0 || total_len == 0)
		return (dest);
	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_cpy(strs[i], &dest[j]);
		if (i != size - 1)
			j += ft_cpy(sep, &dest[j]);
		i++;
	}
	return (dest);
}
