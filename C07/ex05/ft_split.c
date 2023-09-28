/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:18:58 by aradix            #+#    #+#             */
/*   Updated: 2023/09/26 12:08:40 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_split_char(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	toggle;
	int	count;

	i = 0;
	toggle = 1;
	count = 0;
	if (!*charset && *str)
		return (1);
	if (!*charset || !*str)
		return (0);
	while (str[i])
	{
		if (is_split_char(str[i], charset))
			toggle = 1;
		else if (toggle)
		{
			count++;
			toggle = 0;
		}
		i++;
	}
	return (count);
}

char	*cpy_word(char *str, int i, int w_len)
{
	int		j;
	int		size;
	char	*line;

	j = 0;
	size = w_len - i;
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (i < w_len)
	{
		line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*find_and_copy(char *str, int *i, char *charset)
{
	char	*line;
	int		w_len;

	while (str[(*i)] && is_split_char(str[(*i)], charset))
		(*i)++;
	w_len = (*i);
	while (str[w_len] && !is_split_char(str[w_len], charset))
		w_len++;
	line = cpy_word(str, (*i), w_len);
	if (!line)
		return (NULL);
	(*i) = w_len;
	return (line);
}

char	**ft_split(char *str, char *charset)
{
	int		n;
	char	**dest;
	int		i;
	int		j;

	if (!str || !charset)
		return (NULL);
	n = ft_count(str, charset);
	dest = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dest)
		return (NULL);
	dest[n] = NULL;
	if (n == 0)
		return (dest);
	i = 0;
	j = 0;
	while (j < n)
	{
		dest[j] = find_and_copy(str, &i, charset);
		if (!dest[j])
			return (NULL);
		j++;
	}
	return (dest);
}
