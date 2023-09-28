/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:20:25 by npirard           #+#    #+#             */
/*   Updated: 2023/09/24 21:19:17 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

//Return a number as a string if founded within str.
//Follow atoi rules :
//[0-n white :][1 to n digits\stop at any non digit][0-n white space]
//Return NULL if error or if no number is found
char	*parse_value(char *str)
{
	int		i;
	int		j;
	char	*start;

	i = 0;
	while (is_wspace(str[i]))
		i++;
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			return (NULL);
		i++;
	}
	j = i;
	start = str + i;
	while (is_digit(str[j]))
		j++;
	while (str[i] && !is_wspace(str[i]))
		i++;
	while (is_wspace(str[i]))
		i++;
	if (!str[i] && str + j != start)
		return (ft_strndup(start, j));
	return (NULL);
}

//Parse a substring inside str responding to this format
//[0-n white space][any printable character]
//Return a pointer to a copy of the substring if found
//Return NULL if error or no substring found
char	*parse_word(char *str)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
	while (is_wspace(str[i]))
		i++;
	start = str + i;
	while (is_printable(str[i]))
	{
		while (is_printable(str[i]) && str[i] != ' ')
			i++;
		end = str + i;
		while (str[i] == ' ')
			i++;
	}
	while (is_wspace(str[i]))
		i++;
	if (!str[i] && start != end)
		return (ft_strndup(start, end - start));
	return (NULL);
}

int	parse_args(int ac, char **argv, char **path, char **nbr)
{
	if (ac == 2)
	{
		*path = ft_strdup("./numbers.dict");
		*nbr = parse_value(argv[1]);
	}
	else
	{
		*path = ft_strdup(argv[1]);
		*nbr = parse_value(argv[2]);
	}
	if (!*nbr || !*path)
	{
		if (*path)
			free(*path);
		if (*nbr)
			free(*nbr);
		return (1);
	}
	*nbr = round_nbr(*nbr);
	return (0);
}

char	*round_nbr(char *nbr)
{
	int			len;
	char		*buffer;
	char		*prefix;

	buffer = NULL;
	len = ft_strlen(nbr);
	if (len % 3 == 0)
		return (nbr);
	if (len % 3 == 1)
		prefix = "00";
	else
		prefix = "0";
	buffer = malloc((len + ft_strlen(prefix)) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = ft_strcat_to(buffer, prefix, nbr);
	free(nbr);
	return (buffer);
}

int	parse_line(t_entry **dict_head, char *line)
{
	char	**strs;
	char	*nbr;
	char	*word;

	if (!line[0])
		return (0);
	strs = ft_split_first(line, ':');
	if (!strs || !strs[0] || !strs[1] || !strs[0][0] || !strs[1][0])
		return (error(free_line(strs, NULL, NULL, 2)));
	nbr = parse_value(strs[0]);
	word = parse_word(strs[1]);
	if (!nbr || !word)
		return (error(free_line(strs, nbr, word, 2)));
	if (!append_node(dict_head, new_node(nbr, word)))
		return (error(free_line(strs, nbr, word, 3)));
	return (free_line(strs, nbr, word, 0));
}
