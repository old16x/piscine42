/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:17:51 by aradix            #+#    #+#             */
/*   Updated: 2023/09/06 15:42:09 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char c;

	c = 'z';
	while (c >= 'a') {
		write(1, &c, 1);
		c--;
	}
}

int main(void) {
	ft_print_reverse_alphabet();
	return 0;
}

