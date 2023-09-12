/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:22:26 by aradix            #+#    #+#             */
/*   Updated: 2023/09/12 13:14:29 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	int				s;

	i = 0;
	s = 1;
	while (str[i])
	{
		while ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (s && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (!s && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			s = 0;
			i++;
		}
		s = 1;
		i++;
	}
	return (str);
}
