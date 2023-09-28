/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:53:11 by aradix            #+#    #+#             */
/*   Updated: 2023/09/24 21:07:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# define BUFFER_SIZE 100

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_entry {
	int				size;
	char			*key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

//Program methods
t_entry				*build_dict(char *path);
int					error(int error);
int					free_line(char **strs, char *nbr, char *word, int ret);
int					free_all(t_entry **dict, char *path, char *nbr, int error);

//Parsing methods
int					parse_file(t_entry **dict_head, int file);
int					parse_args(int ac, char **av, char **path, char **nbr);
int					parse_line(t_entry **dict_head, char *line);
char				*parse_value(char *str);
char				*round_nbr(char *nbr);

//Strings utils
int					ft_strlen(char *str);
int					ft_strcmp(char *str1, char *str2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
char				*ft_strndup(char *src, int n);
char				*ft_strexpand(char *buffer, char *tail);
char				*ft_strcat_to(char *dest, char *s1, char *s2);
int					ft_atoi(char *str);
int					ft_strchr(char *str, char c);

//Split methods
void				*free_strs(char **strs);
char				**ft_split_first(char *str, char sep);

//Test methods
int					is_digit(char c);
int					is_sign(char c);
int					is_wspace(char c);
int					is_printable(char c);

//Dict methods
t_entry				*new_node(char *key, char *value);
t_entry				*append_node(t_entry **head, t_entry *new_node);
void				*free_node(t_entry *node);
void				*free_dict(t_entry **head);
int					get_dict_size(t_entry *node);
int					solution(char *arg_value, t_entry **head);

//Print methods
void				ft_putstr(char *str);
void				print_dict(t_entry *head);

//Solution
int					tranform_nbr(char *nbr, t_entry **head, char **answer);
int					search_in_dictionary(char *nbr,
						t_entry **head, char **answer);
int					find_unit(int n_zero, t_entry **head, char **answer);

#endif
