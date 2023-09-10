/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:38:04 by aradix            #+#    #+#             */
/*   Updated: 2023/09/10 21:14:11 by jemantel         ###   ########.fr       */
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
