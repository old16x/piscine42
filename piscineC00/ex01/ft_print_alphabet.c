/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:17:51 by aradix            #+#    #+#             */
/*   Updated: 2023/09/06 15:36:28 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char c;

	c = 'a';
	while (c <= 'z') {
		write(1, &c, 1);
		c++;
	}
}

int main(void) {
	ft_print_alphabet();
	return 0;
}
