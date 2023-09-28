/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:57:50 by aradix            #+#    #+#             */
/*   Updated: 2023/09/09 13:32:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int len_line, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < len_line)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == len_line - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	ft_print_line(x, '/', '*', '\\');
	y--;
	while (y > 1)
	{
		ft_print_line(x, '*', ' ', '*');
		y--;
	}
	if (y == 1)
		ft_print_line(x, '\\', '*', '/');
}
