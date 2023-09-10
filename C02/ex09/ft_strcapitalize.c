/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:22:26 by aradix            #+#    #+#             */
/*   Updated: 2023/09/10 11:15:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	s;

	s = 1;
	while (*str)
	{
		while ((*str >= 'a' && *str <= 'z' ) || (*str >= 'A' && *str <= 'Z')
			|| (*str >= '0' && *str <= '9'))
		{
			if (s && *str >= 'a' && *str <= 'z')
				*str -= 32;
			else if (!s && *str >= 'A' && *str <= 'Z')
				*str += 32;
			s = 0;
			str++;
		}
		s = 1;
		str++;
	}
	return (str);
}
