/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:48:15 by aradix            #+#    #+#             */
/*   Updated: 2023/09/28 12:16:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_div(int a, int b);
void	ft_mult(int a, int b);
void	ft_mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

#endif
