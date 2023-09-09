/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:38:04 by aradix            #+#    #+#             */
/*   Updated: 2023/09/09 16:49:37 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *nbr)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == ' '))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (0);
		else
		{
			number = number * 10 + (*nbr - 48);
			nbr++;
		}
	}
	return (number * sign);
}

int	ft_str_to_int(char *str)
{
	int	number;

	number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		else
		{
			number = number * 10 + (*str - 48);
			str++;
		}
	}
	return (number);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
