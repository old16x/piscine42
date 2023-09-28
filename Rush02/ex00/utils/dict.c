/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:04:57 by mairivie          #+#    #+#             */
/*   Updated: 2023/09/24 17:07:25 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

//Takes pointer to first entry of dict
//Free all entries in dict.
//Change head to NULL and return NULL
void	*free_dict(t_entry **head)
{
	t_entry		*current;
	t_entry		*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	*head = NULL;
	return (NULL);
}

//Count element in dict starting from given node.
int	get_dict_size(t_entry *node)
{
	int	i;

	i = 0;
	while (node && node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_entry	*build_dict(char *path)
{
	t_entry		*dict_head;
	int			file;

	dict_head = NULL;
	file = open(path, O_RDONLY);
	if (file < 0)
	{
		error(2);
		return (NULL);
	}
	if (parse_file(&dict_head, file))
		free_dict(&dict_head);
	if (file > 0)
		close(file);
	return (dict_head);
}
