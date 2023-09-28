/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:59:51 by npirard           #+#    #+#             */
/*   Updated: 2023/09/24 15:30:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

//Concatenate s1 with s2 into dest. 
//s1 and s2 must be null terminated.
//Return a pointer toward dest
char	*ft_strcat_to(char *dest, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*buffer;
	int		len_src;
	int		i;

	if (!src)
		return (NULL);
	len_src = ft_strlen(src);
	buffer = malloc((len_src + 1) * sizeof(char));
	if (!buffer)
		return (buffer);
	i = 0;
	while (i < len_src)
	{
		buffer[i] = src[i];
		i++;
	}
	buffer[len_src] = '\0';
	return (buffer);
}

char	*ft_strndup(char *src, int n)
{
	char	*buffer;
	int		len_src;
	int		i;

	if (!src)
		return (NULL);
	len_src = ft_strlen(src);
	buffer = malloc((n + 1) * sizeof(char));
	if (!buffer)
		return (buffer);
	i = 0;
	while (i < n && i < len_src)
	{
		buffer[i] = src[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

//Return a new allocated buffer where src was concatenate with tail.
//Return NULL if allocation fail. src if tail not provided.
//Free src while doing so. src MUST be allocated.
//src and tail MUST be null terminated.
char	*ft_strexpand(char *src, char *tail)
{
	int		l_src;
	int		l_tail;
	char	*buffer;

	if (!tail)
		return (src);
	if (!src)
		l_src = 0;
	else
		l_src = ft_strlen(src);
	l_tail = ft_strlen(tail);
	buffer = malloc((l_src + l_tail + 1) * sizeof(char));
	if (!buffer)
	{
		if (src)
			free(src);
		return (NULL);
	}
	ft_strcat_to(buffer, src, tail);
	free(src);
	return (buffer);
}

/*

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
		{
			str[i] = s2[j];
			i++;
			j++;
		}
	}
	str[i] = '\0';
	return (str);
}*/
