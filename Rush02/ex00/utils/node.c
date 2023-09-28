/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:45:47 by npirard           #+#    #+#             */
/*   Updated: 2023/09/24 17:08:56 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

//Allocate a new node and return the adress of the node.
t_entry	*new_node(char *key, char *value)
{
	t_entry	*node;

	node = (t_entry *)malloc(sizeof(t_entry));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	if (!node->key || !node->value)
		return (free_node(node));
	node->size = ft_strlen(key);
	node->next = (NULL);
	return (node);
}

//Append a new node to chained list dict.
//Return pointer to last node of dict if success.
//If node not provided, free the whole dict and return NULL. 
t_entry	*append_node(t_entry **head, t_entry *new_node)
{
	t_entry	*current;

	if (!new_node)
		return (free_dict(head));
	if (!*head)
	{
		*head = new_node;
		return (*head);
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (*head);
}

//Free node and its elements if they exist
void	*free_node(t_entry *node)
{
	if (node)
	{
		free(node->key);
		free(node->value);
	}
	free(node);
	return (NULL);
}
