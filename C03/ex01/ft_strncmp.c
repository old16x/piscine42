/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:11:32 by aradix            #+#    #+#             */
/*   Updated: 2023/09/13 16:32:00 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (*s1 || *s2))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - ((unsigned char)s2[i]));
		i++;
	}
	return (0);
}

/*
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && (*s1 || *s2))
		if (s1[i] != s2[i])
			return (((char *)s1)[i] - ((char *)s2)[i]);
	return (0);
}*/
