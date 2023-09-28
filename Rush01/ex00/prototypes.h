/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon < neleon@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:21:01 by neleon            #+#    #+#             */
/*   Updated: 2023/09/17 16:53:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	char	**map;
	char	**map_descriptor;
	int		map_size;
}			t_struct;

void		ft_print_matrix(char **m);
char		**ft_create_matrix(unsigned int size_x, unsigned int size_y);
void		ft_putstr(char *s);
int			check_args(const char *raw_map);
char		**create_map_descriptor(char *args, unsigned int map_size);
void		solver(t_struct s_map_struct, int y, int x, int value);

int			check_right_view(char **map, int map_size, int y);
int			check_left_view(char **map, int map_size, int y);
int			check_bottom_view(char **map, int map_size, int x);
int			check_top_view(char **map, int map_size, int x);

void		check_end_of_grid(t_struct s_map_struct, int y);
void		check_cell(t_struct s_map_struct, int y, int x, int value);

void		ft_free_memory(char **s, int size);
int			ft_error(void);
void		ft_exit_success(t_struct s_map_struct);
int			check_map_validity(char **map, char **map_descriptor, int map_size);

int			is_value_in_column(char **map, int y, int x, char value);
int			is_value_in_row(char **map, int y, int x, char value);
int			ft_exit_error(t_struct s_map_struct);
#endif
